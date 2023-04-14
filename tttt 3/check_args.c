/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:11:38 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 02:06:42 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_strs_to_list(char **strs, t_stack *list)
{
	t_stack	*temp;
	int		i ;

	i = 1;
	list->data = ft_atoi(strs[0]);
	list->next = NULL;
	while (strs[i])
	{
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(strs[i])));
		i++;
	}
	temp = list;
	while (temp)
	{
		temp->index = -1;
		temp = temp->next;
	}
}

void	ft_check_args_one(int i, int j, char **strs, int *check)
{
	i = 1;
	j = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if ((strs[i][j] < '0' || strs[i][j] > '9') && strs[i][j] != ' '
			&& strs[i][j] != '-' && strs[i][j] != '+')
				check[1] = 1;
			if (strs[i][j] == '+' || strs[i][j] == '-')
			{
				if (j > 0 && strs[i][j - 1] != ' ')
					check[1] = 1;
				if (strs[i][j + 1] > '9' || strs[i][j + 1] < '0')
					check[1] = 1;
			}
			j++;
		}
		i++;
	}
	ft_check_args_two(check);
}

void	ft_check_args(char **strs)
{
	int	i;
	int	j;
	int	check[2];

	i = 1;
	j = 0;
	check[0] = 0;
	check[1] = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] >= '0' && strs[i][j] <= '9')
				check[0] = 1;
			j++;
		}
		i++;
	}
	ft_check_args_one(i, j, strs, check);
}

void	check_empty_string(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!av[i][0])
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
