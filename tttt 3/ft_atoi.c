/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:51:25 by isbarka           #+#    #+#             */
/*   Updated: 2023/03/17 00:54:53 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_tab_or_space(char c)
{
	if (c == '\t' || c == '\n'
		|| c == ' ' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	ft_result_to_return(const char *str, int sign)
{
	int	res;
	int	i;
	int	temp;

	temp = 0;
	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = res;
		res = res * 10 + str[i] - '0';
		i++;
		if (temp != res / 10 && sign == 1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (temp != res / 10 && sign == -1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	return (res * sign);
}

int	ft_min_int(const char *str)
{
	if (str[0] == '-' && str[1] == '2' && str[2] == '1'
		&& str[3] == '4' && str[4] == '7'
		&& str[5] == '4' && str[6] == '8' && str[7] == '3'
		&& str[8] == '6' && str[9] == '4' && str[10] == '8')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	i;
	long long	sign;

	i = 0;
	sign = 1;
	while (ft_tab_or_space(str[i]))
		i++;
	if (ft_min_int(&str[i]))
		return (-2147483648);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	return (ft_result_to_return (&str[i], sign));
}
