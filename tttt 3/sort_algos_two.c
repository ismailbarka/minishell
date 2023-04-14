/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:36:48 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/11 17:09:02 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a, t_moves **moves_count)
{
	while (1)
	{
		if ((*stack_a)->index < (*stack_a)->next->index
			&& (*stack_a)->index < (*stack_a)->next->next->index
			&& (*stack_a)->next->index < (*stack_a)->next->next->index)
			return ;
		if ((*stack_a)->index > (*stack_a)->next->index
			&& (*stack_a)->index > (*stack_a)->next->next->index)
			ra(stack_a, moves_count);
		if ((*stack_a)->next->index > (*stack_a)->index
			&& (*stack_a)->next->index > (*stack_a)->next->next->index)
			rra(stack_a, moves_count);
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a, moves_count);
	}
}

void	sort_two(t_stack **stack_a, t_moves **moves_count)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, moves_count);
}

int	ft_big_pos_two(t_stack *temp, t_stack **stack_b, int count, int bigger)
{
	int	index;

	index = 0;
	while (temp)
	{
		if (temp->index > count && temp->index != bigger)
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

void	sort_hundred_one(t_stack **s_a, t_stack **s_b, t_moves **m_c, int check)
{
	while ((*s_b))
	{
		if (ft_big_pos(s_b) == 0 || (ft_big_pos_one(s_b) == 0 && check == 0))
		{
			if (ft_big_pos_one(s_b) == 0)
				check = 1;
			if (ft_big_pos(s_b) == 0)
				check = 0;
			pa(s_a, s_b, m_c);
			if ((*s_a) && (*s_a)->next && (*s_a)->index > (*s_a)->next->index)
			{
				if ((*s_b) && (*s_b)->next && (*s_b)->index
					> (*s_b)->next->index)
					ss(s_a, s_b, m_c);
				else
					sa(s_a, m_c);
			}
		}
		else if (ft_listsize(*s_b) - ft_big_pos(s_b) < ft_big_pos(s_b))
			rrb(s_b, m_c);
		else if (ft_listsize(*s_b) - ft_big_pos(s_b) >= ft_big_pos(s_b))
			rb(s_b, m_c);
	}
}
