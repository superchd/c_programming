/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:02:07 by hchd              #+#    #+#             */
/*   Updated: 2021/03/15 09:55:45 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (*(base + i))
	{
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
			{
				return (-1);
			}
			if (*(base + i) == '-' || *(base + i) == '+')
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int k;

	while (*str)
	{
		str++;
		k++;
	}
	return (k - 1);
}

int	find_index(char str, char *base)
{
	int index;

	index = 0;
	while (str != *base)
	{
		base++;
		index++;
	}
	return (index);
}

int	power(int n, int m)
{
	int answer;

	answer = 1;
	if (m == 0)
		return (1);
	else
	{
		answer = n * power(n, m - 1);
	}
	return (answer);
}

int	ft_atoi_base(char *str, char *base)
{
	int base_len;
	int str_len;
	int num;
	int sum;

	sum = 0;
	base_len = check_base(base);
	str_len = ft_strlen(str);
	if (base_len == -1)
	{
		return (-1);
	}
	while (--str_len != -1)
	{
		num = find_index(*str, base) * power(base_len, str_len);
		sum += num;
	}
	return (sum);
}
