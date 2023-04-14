/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:37:39 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/10 16:47:04 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*my_node;

	my_node = malloc(sizeof(t_stack));
	if (!my_node)
	{
		return (NULL);
	}
	my_node -> data = content;
	my_node -> next = NULL;
	return (my_node);
}

t_moves	*ft_lstnew_one(int content)
{
	t_moves	*my_node;

	my_node = malloc(sizeof(t_moves));
	if (!my_node)
	{
		return (NULL);
	}
	my_node -> data = content;
	my_node -> next = NULL;
	return (my_node);
}
