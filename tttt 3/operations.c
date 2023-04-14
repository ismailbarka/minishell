/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:13:45 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 00:48:38 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	sa(t_stack **head, t_moves **moves_count)
{
	sa_(head);
	ft_lstadd_back_one(moves_count, ft_lstnew_one(1));
}

void	sb(t_stack **head, t_moves **moves_count)
{
	ft_lstadd_back_one(moves_count, ft_lstnew_one(2));
	sa_(head);
}

void	ss_(t_stack **stack_a, t_stack **stack_b)
{
	sa_(stack_a);
	sa_(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_moves **moves_count)
{
	ft_lstadd_back_one(moves_count, ft_lstnew_one(3));
	sa_(stack_a);
	sa_(stack_b);
}
