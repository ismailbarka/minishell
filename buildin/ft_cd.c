#include "minishell.h"

char *args_without_the_last(char **strs)
{
    int i = 0;
    // while(strs[i])
    // {
    //     printf("||%s\n",strs[i]);
    //     i++;
    // }
    char *to_return = NULL;
    int count_args = 0;
    i = 0;
    while(strs[count_args])
    {
        count_args++;
    }
    while(i < count_args - 1)
    {
        to_return = ft_strjoin(to_return, "/");
        to_return = ft_strjoin(to_return, strs[i]);
        i++;
    }
    return to_return;
}

char *ft_home_path(char *env)
{

    char *path;

    int start = 0;
    int end = 0;
    int i = 0;
    while(env && env[start] != '=')
    {
        start++;
    }
    start++;
    end = ft_strlen(env);
    path = ft_calloc(end - start + 1, sizeof(char));
    while(env[start])
    {
        path[i] = env[start];
        start++;
        i++;
    }
    return path;
}

void ft_go_home(t_parsed *lexe)
{
    int i = 0;
    while(lexe->envs[i])
    {
        if(lexe->envs[i][0] == 'H' && lexe->envs[i][1] == 'O' && lexe->envs[i][2] == 'M' && lexe->envs[i][3] == 'E')
        {
            chdir(ft_home_path(lexe->envs[i]));
            break ;
        }
        i++;
    }
}

void ft_cd(t_parsed *lexe)
{
    if(!lexe->args || !*(lexe->args) || strcmp("cd", lexe->args[0]) != 0)
        return ;
    if(lexe->args[1] == NULL)
        ft_go_home(lexe);
    else if(lexe->args[1][0] == '~' && lexe->args[1][1] == '\0')
        ft_go_home(lexe);
    else
        chdir(lexe->args[1]);
    ft_pwd(lexe);
}
