/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:11:38 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 02:06:25 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_join_args(char **av)
{
	char	*to_return ;
	int		i;

	to_return = NULL;
	i = 1;
	while (av[i])
	{
		to_return = ft_strjoin(to_return, " ");
		to_return = ft_strjoin(to_return, av[i]);
		i++;
	}
	return (to_return);
}

void	ft_check_args_two(int *check)
{
	if (check[0] == 0 || check[1] == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
