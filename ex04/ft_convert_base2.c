/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:43:05 by hchd              #+#    #+#             */
/*   Updated: 2021/03/17 18:43:27 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_base(char str, char *base)
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

int	check_base(char *base)
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
		if (*(base + i) == ' ')
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

bool	exception(char *base_from, char *base_to)
{
	int	from_len;
	int	to_len;

	from_len = check_base(base_from);
	to_len = check_base(base_to);
	if (from_len <= 1 || to_len <= 1)
		return (false);
	return (true);
}
