/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:13:45 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 00:48:55 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_(t_stack **stack_a, t_stack **stack_b)
{
	ra_(stack_a);
	ra_(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_moves **moves_count)
{
	ft_lstadd_back_one(moves_count, ft_lstnew_one(8));
	ra_(stack_a);
	ra_(stack_b);
}

void	rra_(t_stack **stack_a)
{
	t_stack	*second_last_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	second_last_node = *stack_a;
	while (second_last_node->next->next != NULL)
		second_last_node = second_last_node->next;
	second_last_node->next->next = *stack_a;
	*stack_a = second_last_node->next;
	second_last_node->next = NULL;
}

void	rra(t_stack **stack_a, t_moves **moves_count)
{
	ft_lstadd_back_one(moves_count, ft_lstnew_one(9));
	rra_(stack_a);
}

void	rrb(t_stack **stack_a, t_moves **moves_count)
{
	ft_lstadd_back_one(moves_count, ft_lstnew_one(10));
	rra_(stack_a);
}
