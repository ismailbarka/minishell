/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:36:48 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 02:03:46 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_smaller(t_stack **s_a, t_stack **s_b, t_moves **m_c)
{
	t_stack	*temp;
	int		min1[2];

	temp = (*s_a);
	min1[0] = temp->index;
	min1[1] = temp->index;
	temp = (*s_a);
	min1[0] = temp->index;
	min1[1] = temp->index;
	while (temp)
	{
		if (temp->index < min1[0])
			min1[0] = temp->index;
		temp = temp->next;
	}
	temp = (*s_a);
	push_smaller_one(s_a, min1, s_b, m_c);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, t_moves **moves_count)
{
	int	count;
	int	i;

	count = ft_listsize(*stack_a);
	i = 3;
	while (i < count)
	{
		i++;
		push_smaller(stack_a, stack_b, moves_count);
	}
	sort_three(stack_a, moves_count);
	pa(stack_a, stack_b, moves_count);
	pa(stack_a, stack_b, moves_count);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, moves_count);
}
