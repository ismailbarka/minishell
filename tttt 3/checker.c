/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:05:15 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 17:13:37 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_cmpp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	check_word(char *strs)
{
	if (strs && check_word_one(strs) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	do_cmnds(t_chars chars, int i, t_stack *stack_a, t_stack *stack_b)
{
	while (chars.buff2d && chars.buff2d[i])
	{
		if (ft_strncmp(chars.buff2d[i], "sa", 2) == 0
			&& ft_strlen(chars.buff2d[i]) == 2)
			sa_(&stack_a);
		else if (ft_strncmp(chars.buff2d[i], "sb", 2) == 0
			&& ft_strlen(chars.buff2d[i]) == 2)
			sa_(&stack_b);
		else if (ft_strncmp(chars.buff2d[i], "ss", 2) == 0)
			ss_(&stack_a, &stack_b);
		else if (ft_strncmp(chars.buff2d[i], "pa", 2) == 0
			&& ft_strlen(chars.buff2d[i]) == 2)
			pa_(&stack_a, &stack_b);
		else if (ft_strncmp(chars.buff2d[i], "pb", 2) == 0
			&& ft_strlen(chars.buff2d[i]) == 2)
			pa_(&stack_b, &stack_a);
		else
			do_cmnds_one(stack_a, stack_b, chars, i);
		i++;
	}
}

char	**read_from_pipe(void)
{
	char	*buff;
	char	**buff2d;
	char	*new;

	buff = NULL;
	buff2d = NULL;
	new = NULL;
	while (1)
	{
		new = get_next_line(0);
		if (new == NULL)
			break ;
		if (!buff)
		{
			if (new && new[0] == '\n')
				exit(1);
		}
		check_word(new);
		read_from_pipe_one(buff, new);
		buff = ft_strjoin_one(buff, new);
		free(new);
	}
	buff2d = ft_split(buff, '\n');
	return (buff2d);
}

int	main(int ac, char **av)
{
	t_chars	chars;
	char	*str;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 0;
	if (ac <= 1)
		exit(0);
	check_empty_string(av);
	ft_check_args(av);
	str = ft_join_args(av);
	chars.strs = ft_split(str, ' ');
	stack_a = malloc(sizeof(t_stack));
	ft_add_strs_to_list(chars.strs, stack_a);
	check_duplicat(stack_a, 1);
	stack_b = NULL;
	ft_indexlst(&stack_a);
	chars.buff2d = read_from_pipe();
	do_cmnds(chars, i, stack_a, stack_b);
	ok_ko(stack_a);
}
