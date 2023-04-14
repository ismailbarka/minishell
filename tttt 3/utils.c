/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:37:39 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/10 16:48:10 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_listsize(t_stack *list)
{
	int	count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstdelone(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	if (!temp)
		return ;
	stack_a = stack_a->next;
	free(temp);
	temp = NULL;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*my_lst;

	if (!lst || !new)
		return ;
	my_lst = *lst;
	if (my_lst)
	{
		while (my_lst->next != NULL)
			my_lst = my_lst->next;
		my_lst->next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_back_one(t_moves **lst, t_moves *new)
{
	t_moves	*my_lst;

	if (!lst || !new)
		return ;
	my_lst = *lst;
	if (my_lst)
	{
		while (my_lst->next != NULL)
			my_lst = my_lst->next;
		my_lst->next = new;
	}
	else
		*lst = new;
}
