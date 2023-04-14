/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:35:36 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 01:11:04 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexlst_one(int *d, t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->data == d[2] && temp->index == -1)
		{
			temp->index = d[0];
			d[0]++;
			break ;
		}
		temp = temp->next;
	}
}

void	ft_indexlst(t_stack **stack_a)
{
	t_stack	*temp;
	int		d[3];

	d[1] = -1;
	d[0] = 0;
	while (not_indexeed(stack_a))
	{
		temp = *stack_a;
		d[2] = 2147483647;
		while (temp)
		{
			if (temp->data < d[2] && temp->index == -1)
				d[2] = temp->data;
			temp = temp->next;
		}
		ft_indexlst_one(d, stack_a);
		d[1] = d[2];
	}
}

void	ft_strcmp(int a, t_stack *stack_a, int i)
{
	while (stack_a)
	{
		if (stack_a->data == a)
		{
			if (i == 0)
				write(2, "Error\n", 6);
			else
				write(2, "Error\n", 6);
			exit(1);
		}
		stack_a = stack_a->next;
	}
}

int	not_indexeed(t_stack **stack_a)
{
	t_stack	*temp;

	temp = (*stack_a);
	while (temp)
	{
		if (temp->index == -1)
		{
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void	check_duplicat(t_stack *stack_a, int i)
{
	while (stack_a)
	{
		ft_strcmp(stack_a->data, stack_a->next, i);
		stack_a = stack_a->next;
	}
}
