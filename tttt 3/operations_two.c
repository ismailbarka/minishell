/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:10:21 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 19:18:36 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_(t_stack **s_a, t_stack **stack_b)
{
	t_stack	*node;

	if (*s_a == NULL)
	{
		return ;
	}
	node = *s_a;
	*s_a = (*s_a)->next;
	if (*stack_b == NULL)
	{
		*stack_b = node;
		(*stack_b)->next = NULL;
	}
	else
	{
		node->next = *stack_b;
		*stack_b = node;
	}
}

void	check_sorted(t_stack **s_a)
{
	t_stack	*temp;

	temp = (*s_a);
	while (temp)
	{
		if (temp && temp->next
			&& temp->data > temp->next->data)
		{
			return ;
		}
		temp = temp->next;
	}
	exit(0);
}

void	free_all(t_stack **s_a, t_moves **m_c, char **strs, char *str)
{
	int	i ;

	i = 0;
	ft_lstclear(s_a);
	ft_lstclear_one(m_c);
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	free(str);
}
