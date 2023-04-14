/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:36:48 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 00:09:21 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_big_pos_one(t_stack **s_b)
{
	int		count;
	int		index;
	int		bigger;
	t_stack	*temp;

	count = 0;
	index = 0;
	bigger = -1;
	temp = (*s_b);
	while (temp)
	{
		if (temp->index > count)
			bigger = temp->index;
		temp = temp->next;
	}
	temp = (*s_b);
	return (ft_big_pos_two(temp, s_b, count, bigger));
}

void	sort_hundred(t_stack **s_a, t_stack **s_b, t_moves **m_c)
{
	int	count;
	int	check;

	check = 0;
	count = 24;
	while ((*s_a))
	{
		while (there_is_count(count, s_a))
			push_first_20(count, s_a, s_b, m_c);
		count = count + 24;
	}
	sort_hundred_one(s_a, s_b, m_c, check);
}

int	minpos(int min, t_stack **stack_a)
{
	t_stack	*temp;
	int		count;

	temp = (*stack_a);
	count = 0;
	temp = (*stack_a);
	count = 0;
	while (temp)
	{
		if (temp->index == min)
			break ;
		count++;
		temp = temp->next;
	}
	return (count);
}

void	push_smaller_two(int *min1, t_stack **s_a, t_stack **s_b, t_moves **m_c)
{
	while (1)
	{
		if (minpos(min1[0], s_a) == 0
			|| (minpos(min1[1], s_a) == 0 && ft_listsize(*s_a) == 5))
		{
			pb(s_a, s_b, m_c);
			break ;
		}
		else if (minpos(min1[0], s_a) > ft_listsize(*s_a)
			|| (minpos(min1[1], s_a) > ft_listsize(*s_a)
				&& ft_listsize(*s_a) == 5))
			rra(s_a, m_c);
		else if (minpos(min1[0], s_a) <= ft_listsize(*s_a)
			|| (minpos(min1[1], s_a) <= ft_listsize(*s_a)
				&& ft_listsize(*s_a) == 5))
			ra(s_a, m_c);
	}
}

void	push_smaller_one(t_stack **s_a, int *min1, t_stack **s_b, t_moves **m_c)
{
	t_stack	*temp;

	temp = (*s_a);
	while (temp)
	{
		if (temp->index < min1[1] && temp->index != min1[0])
			min1[1] = temp->index;
		temp = temp->next;
	}
	push_smaller_two(min1, s_a, s_b, m_c);
}
