/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:38:55 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 19:28:28 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_list(char **av, t_stack *list)
{
	int	i;

	i = 1;
	list->data = ft_atoi(av[i]);
	i++;
	while (av[i])
	{
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, t_moves **moves_count)
{
	if (ft_listsize(*stack_a) < 1)
	{
		exit(1);
	}
	if (ft_listsize(*stack_a) == 1)
		return ;
	if (ft_listsize(*stack_a) == 2)
		sort_two(stack_a, moves_count);
	else if (ft_listsize(*stack_a) == 3)
		sort_three(stack_a, moves_count);
	else if (ft_listsize(*stack_a) <= 5)
		sort_five(stack_a, stack_b, moves_count);
	else if (ft_listsize(*stack_a) <= 100)
		sort_hundred(stack_a, stack_b, moves_count);
	else
		sort_500(stack_a, stack_b, moves_count);
}

void	print_moves_one(t_moves **moves_count)
{
	if ((*moves_count)->data == 5)
		write(1, "pb\n", 3);
	else if ((*moves_count)->next && (((*moves_count)->data == 6
				&& (*moves_count)->next->data == 7)
			|| ((*moves_count)->data == 7 && (*moves_count)->next->data == 6)))
	{
		write(1, "rr\n", 3);
		(*moves_count) = (*moves_count)->next;
	}
	else if ((*moves_count)->data == 6)
		write(1, "ra\n", 3);
	else if ((*moves_count)->data == 7)
		write(1, "rb\n", 3);
	else if ((*moves_count)->data == 9)
		write(1, "rra\n", 4);
	else if ((*moves_count)->data == 10)
		write(1, "rrb\n", 4);
}

void	print_moves(t_moves **moves_count)
{
	t_moves	*temp ;

	temp = *moves_count;
	while (temp)
	{
		if (temp->next && ((temp->data == 1
					&& temp->next->data == 2)
				|| (temp->data == 2
					&& temp->next->data == 1)))
		{
			write(1, "ss\n", 3);
			temp = temp->next;
		}
		else if (temp->data == 1)
			write(1, "sa\n", 3);
		else if (temp->data == 3)
			write(1, "ss\n", 3);
		else if (temp->data == 2)
			write(1, "sb\n", 3);
		else if (temp->data == 4)
			write(1, "pa\n", 3);
		else
			print_moves_one(&temp);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_moves	*moves_count;
	char	*str;
	char	**strs;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <= 1)
		exit(0);
	moves_count = malloc(sizeof(t_moves));
	moves_count->next = NULL;
	moves_count->data = -2;
	check_empty_string(av);
	ft_check_args(av);
	str = ft_join_args(av);
	strs = ft_split(str, ' ');
	stack_a = malloc(sizeof(t_stack));
	ft_add_strs_to_list(strs, stack_a);
	check_duplicat(stack_a, 0);
	stack_b = NULL;
	ft_indexlst(&stack_a);
	check_sorted(&stack_a);
	ft_sort(&stack_a, &stack_b, &moves_count);
	print_moves(&moves_count);
	free_all(&stack_a, &moves_count, strs, str);
}
