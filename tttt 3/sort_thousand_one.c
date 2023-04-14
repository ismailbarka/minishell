/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_thousand_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:49:01 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/11 15:59:03 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_500(t_stack **stack_a, t_stack **stack_b, t_moves **moves_count)
{
	int	count;

	count = 55;
	while ((*stack_a))
	{
		while (there_is_count(count, stack_a))
		{
			push_first_500(count, stack_a, stack_b, moves_count);
		}
		count = count + 55;
	}
	push_back_to_a(stack_a, stack_b, moves_count);
}
