/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:43:05 by hchd              #+#    #+#             */
/*   Updated: 2021/03/16 02:00:16 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_white_space(char str)
{
	if (('\t' <= str && str <= '\r') || str == ' ')
		return (true);
}

bool	is_base_number(char str, char *base)
{
	int cnt;

	cnt = 0;
	while (*base)
	{
		if (str == *base++)
			cnt++;
	}
	if (cnt == 1)
		return (true);
	else
		return (false);
}

int	check_right_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (*(base + i))
	{
		if (*(base + i) == '-' || *(base + i) == '+')
			return (-1);
		if ((*(base + i) >= '\t' && *(base + i) <= '\r'))
			return (-1);
		if (*(base + i) == ' ' || !is_base(*(base + i), base))
			return (-1);
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}
int	power(int base_len, int m)
{
	int answer;

	answer = 1;
	if (m == 0)
		return (1);
	else
	{
		answer = base_len * power(base_len, m - 1);
	}
	return (answer);
}

int	transfer_to_int(char str, char *clear_str, char *base, int base_len)
{
	int	index;
	int	len;
	int	i;

	i = 0;
	index = 0;
	len = 0;
	while (*base)
	{
		if (str == *base)
			break;
		index++;
		base++;
	}
	while (*clear_str && is_base(*clear_str, base))
	{
			clear_str++;
			len++;
	}
	return (index * power(base_len, len - 1));
}
