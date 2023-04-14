/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:52:11 by isbarka           #+#    #+#             */
/*   Updated: 2022/10/29 04:52:11 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*p;

	if (!lst)
		return ;
		p = *lst;
	while (p)
	{
		p = p->next;
		free (*lst);
		*lst = p;
	}
	lst = NULL;
}

void	ft_lstclear_one(t_moves **lst)
{
	t_moves	*p;

	if (!lst)
		return ;
		p = *lst;
	while (p)
	{
		p = p->next;
		free (*lst);
		*lst = p;
	}
	lst = NULL;
}
