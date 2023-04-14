/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:05:15 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/16 17:19:32 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_cmnds_one(t_stack *stack_a, t_stack *stack_b, t_chars chars, int i)
{
	if (ft_strncmp(chars.buff2d[i], "ra", 2) == 0
		&& ft_strlen(chars.buff2d[i]) == 2)
		ra_(&stack_a);
	else if (ft_strncmp(chars.buff2d[i], "rb", 2) == 0
		&& ft_strlen(chars.buff2d[i]) == 2)
		ra_(&stack_b);
	else if (ft_strncmp(chars.buff2d[i], "rr", 2) == 0
		&& ft_strlen(chars.buff2d[i]) == 2)
		rr_(&stack_a, &stack_b);
	else if (ft_strncmp(chars.buff2d[i], "rra", 3) == 0
		&& ft_strlen(chars.buff2d[i]) == 3)
		rra_(&stack_a);
	else if (ft_strncmp(chars.buff2d[i], "rrb", 3) == 0
		&& ft_strlen(chars.buff2d[i]) == 3)
		rra_(&stack_b);
}

int	check_word_one(char *str)
{
	if (ft_strncmp(str, "sa", 2) == 0 && ft_strlen(str) == 3)
		return (1);
	else if (ft_strncmp(str, "sb", 2) == 0 && ft_strlen(str) == 3)
		return (1);
	else if (ft_strncmp(str, "ss", 2) == 0 && ft_strlen(str) == 3)
		return (1);
	else if (ft_strncmp(str, "pa", 2) == 0 && ft_strlen(str) == 3)
		return (1);
	else if (ft_strncmp(str, "pb", 2) == 0 && ft_strlen(str) == 3)
		return (1);
	else if (ft_strncmp(str, "ra", 2) == 0 && ft_strlen(str) == 3)
		return (1);
	else if (ft_strncmp(str, "rb", 2) == 0 && ft_strlen(str) == 3)
		return (1);
	else if (ft_strncmp(str, "rr", 2) == 0 && ft_strlen(str) == 3)
		return (1);
	else if (ft_strncmp(str, "rra", 3) == 0 && ft_strlen(str) == 4)
		return (1);
	else if (ft_strncmp(str, "rrb", 3) == 0 && ft_strlen(str) == 4)
		return (1);
	else if (ft_strncmp(str, "rrr", 3) == 0 && ft_strlen(str) == 4)
		return (1);
	return (0);
}

void	read_from_pipe_one(char *buff, char *new)
{
	if (buff && new && buff[ft_strlen(buff) - 1] == '\n' && new[0] == '\n')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	ok_ko(t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a && stack_a->next && stack_a->data > stack_a->next->data)
		{
			write(1, "KO\n", 3);
			exit(1);
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
}
