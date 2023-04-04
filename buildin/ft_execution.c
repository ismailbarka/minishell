#include "minishell.h"

void	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

char	*ft_path(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i][0] == 'P' && str[i][1] == 'A' && str[i][2] == 'T')
			return (&str[i][5]);
		i++;
	}
	return (NULL);
}

char	**errs(char **env)
{
	char	**paths;

	paths = ft_split(ft_path(env), ':');
	return (paths);
}

char	*ft_valid_path(char **paths, char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (access(str, X_OK) == 0)
		return (str);
	while (paths[i])
	{
        temp = ft_strjoin(paths[i], "/");
		temp = ft_strjoin(temp, str);
		if (access(temp, X_OK) == 0)
        {
			return (temp);
        }
            
		free(temp);
		i++;
	}
	return (NULL);
}

void	check_error(int x, char *str)
{
	if (x < 0)
	{
		ft_putstr(2, str);
		exit(1);
	}
}

void ft_first_cmnd_two(t_parsed *lexe)
{
    char	**paths;
	char	**temp;
	char	*valid_path;

    paths = errs(lexe->envs);
    valid_path = ft_valid_path(paths, lexe->args[0]);
    if (valid_path == NULL)
    {
    
		check_error(-1, "command not found");
        exit(1);
    }
    // printf("valid path = %s \n", valid_path);
    // int a = 0;
    // while(lexe->args[a])
    // {
    //     printf("lexe.args[%d] = %s", a,lexe->args[a]);
    //     a++;
    // }
    execve(valid_path, lexe->args, NULL);
	exit(1);
}

void ft_first_cmnd_one(t_parsed *lexe)
{
    int a_fd;
    int check;
    int test;

    a_fd = open("/tmp/a", O_CREAT | O_RDWR | O_TRUNC, 0644);
    if(lexe->next)
    {
        check = dup2(a_fd, 1);
    }   
    else
    {
        check = dup2(lexe->out, 1);
    }
    ft_first_cmnd_two(lexe);
     
}

void ft_first_cmnd(t_parsed *lexe)
{
    if(lexe->in != -2)
        dup2(lexe->in, 0);
    close(lexe->in);
    int check = fork();
    if(check == 0)
    {
        
        ft_first_cmnd_one(lexe);
    }
    wait(0);
}

void ft_execution(t_parsed *lexe)
{
    int check = 1;

    ft_first_cmnd(lexe);
    lexe = lexe->next;
    while(lexe)
    {
        if(lexe->next == NULL)
        {
            // ft_last_cmnd(lexe);
        }
        else
        {
            // ft_middle_cmnd(lexe, check);
            check = - check;
        }
        lexe = lexe->next;
    }
    
}