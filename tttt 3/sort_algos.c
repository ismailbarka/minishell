/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:36:48 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/11 16:50:27 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	there_is_count(int count, t_stack **stack_a)
{
	t_stack	*temp;

	temp = (*stack_a);
	while (temp)
	{
		if ((temp)->index <= count)
			return (1);
		(temp) = (temp)->next;
	}
	return (0);
}

int	index_pos(int count, t_stack **stack_a)
{
	int		to_return;
	int		count_;
	t_stack	*temp;

	count_ = 0;
	temp = (*stack_a);
	to_return = 0;
	while (temp)
	{
		if (temp->index <= count)
		{
			to_return = count_;
			break ;
		}
		count_++;
		temp = temp->next;
	}
	return (to_return);
}

void	edit_stack_b(int count, t_stack **stack_b, t_moves **moves_count)
{
	if (!(*stack_b))
		return ;
	if ((*stack_b)->index > count - 12)
		rb(stack_b, moves_count);
}

void	push_first_20(int c, t_stack **s_a, t_stack **s_b, t_moves **moves_c)
{
	edit_stack_b(c, s_b, moves_c);
	if (index_pos(c, s_a) == 0)
	{
		pb(s_a, s_b, moves_c);
		return ;
	}
	if (index_pos(c, s_a) > ft_listsize((*s_a)) / 2)
	{
		rra(s_a, moves_c);
		return ;
	}
	if (index_pos(c, s_a) <= ft_listsize((*s_a)) / 2)
	{
		ra(s_a, moves_c);
		return ;
	}
}

int	ft_big_pos(t_stack **stack_b)
{
	int		count;
	int		index;
	t_stack	*temp;

	count = 0;
	index = 0;
	temp = (*stack_b);
	while (temp)
	{
		if (temp->index > count)
			count = temp->index;
		temp = temp->next;
	}
	temp = (*stack_b);
	while (temp)
	{
		if (temp->index == count)
			return (index);
		index++;
		temp = temp->next;
	}
	return (0);
}
