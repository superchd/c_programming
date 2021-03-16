/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:13:52 by hchd              #+#    #+#             */
/*   Updated: 2021/03/12 20:03:35 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	is_white_space(char str)
{
	if (str == ' ' || str == '\t' || str == '\n')
		return (true);
	else
		return (false);
}

int	flag(char str)
{
	if (str >= '0' && str <= '9')
		return (0);
	else if (str == '+')
		return (1);
	else if (str == '-')
		return (2);
	else
		return (3);
}

int	sign(char *str)
{
	int plus_cnt;
	int minus_cnt;

	plus_cnt = 0;
	minus_cnt = 0;
	while (flag(*str) == 1 || flag(*str) == 2)
	{
		if (flag(*str) == 2)
			minus_cnt++;
		str++;
	}
	if (minus_cnt % 2 == 1)
		return (-1);
	else
		return (1);
}

int	ft_atoi(char *str)
{
	int sum;
	int plus_minus;

	sum = 0;
	while (is_white_space(*str))
		str++;
	plus_minus = sign(str);
	while (flag(*str) == 1 || flag(*str) == 2)
		str++;
	if (flag(*str) != 0)
		return (0); 
	while (flag(*str) == 0)
	{
		sum = sum * 10 + *str - '0';
		++str;
	}
	return (plus_minus * sum);
}
