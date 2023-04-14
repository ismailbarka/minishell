/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:13:45 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 00:46:04 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, t_moves **moves_count)
{
	ft_lstadd_back_one(moves_count, ft_lstnew_one(4));
	pa_(stack_b, stack_a);
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_moves **moves_count)
{
	ft_lstadd_back_one(moves_count, ft_lstnew_one(5));
	pa_(stack_a, stack_b);
}

void	ra_(t_stack **stack_a)
{
	t_stack	*last_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last_node = *stack_a;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = *stack_a;
	*stack_a = (*stack_a)->next;
	last_node->next->next = NULL;
}

void	ra(t_stack **stack_a, t_moves **moves_count)
{
	ft_lstadd_back_one(moves_count, ft_lstnew_one(6));
	ra_(stack_a);
}

void	rb(t_stack **stack_b, t_moves **moves_count)
{
	ft_lstadd_back_one(moves_count, ft_lstnew_one(7));
	ra_(stack_b);
}
