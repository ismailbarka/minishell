/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_thousand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:49:01 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/11 15:59:33 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	edit_stack_b_one(int count, t_stack **stack_b, t_moves **moves_count)
{
	if (!(*stack_b))
		return ;
	if ((*stack_b)->index > count - 27)
		rb(stack_b, moves_count);
}

void	push_first_500(int count, t_stack **s_a, t_stack **s_b, t_moves **m_c)
{
	edit_stack_b_one(count, s_b, m_c);
	if (index_pos(count, s_a) == 0)
	{
		pb(s_a, s_b, m_c);
		return ;
	}
	if (index_pos(count, s_a) > ft_listsize((*s_a)) / 2)
	{
		rra(s_a, m_c);
		return ;
	}
	if (index_pos(count, s_a) <= ft_listsize((*s_a)) / 2)
	{
		ra(s_a, m_c);
		return ;
	}
}

int	finder(t_stack **stack, int pos)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*stack);
	while (tmp)
	{
		if (tmp->index == pos)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	highest_index(t_stack *stack)
{
	int	highest;

	highest = stack->index;
	while (stack)
	{
		if (stack->index > highest)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b, t_moves **m_c)
{
	while ((*stack_b))
	{
		if ((*stack_b)->index == highest_index(*stack_b)
			|| (*stack_b)->index == highest_index(*stack_b) - 1)
			pa(stack_a, stack_b, m_c);
		else if (finder(stack_b, highest_index(*stack_b))
			> ft_listsize(*stack_b) / 2)
			while (!((*stack_b)->index == highest_index(*stack_b)
					|| (*stack_b)->index == highest_index(*stack_b) - 1))
				rrb(stack_b, m_c);
		else
			while (!((*stack_b)->index == highest_index(*stack_b)
					|| (*stack_b)->index == highest_index(*stack_b) - 1))
				rb(stack_b, m_c);
		if (ft_listsize(*stack_a) > 1
			&& (*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a, m_c);
	}
}
