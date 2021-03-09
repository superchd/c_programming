/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:13:52 by hchd              #+#    #+#             */
/*   Updated: 2021/03/09 00:32:30 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	sign(char *str)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == '-')
			cnt++;
		str++;
	}
	if (cnt % 2 == 0)
		return (1);
	else
		return (-1);
}

int	str_to_i(char *p)
{
	int sum;

	sum = 0;
	while (*p)
	{
		*p -= '0';
		sum = sum * 10 + *p;
		p++;
	}
	return (sum);
}

int	ft_atoi(char *str)
{
	int	answer;
	int	plus_minus;
	char	*clear_str;
	char	*final_str;

	plus_minus = sign(str);
	while (!(*str >= '0' && *str <= '9'))
		str++;
	clear_str = str;
	final_str = clear_str;
	while (*str >= '0' && *str <= '9')
		*clear_str++ = *str++;
	*clear_str = 0;
	answer = str_to_i(final_str);
	return (answer * plus_minus);
}
