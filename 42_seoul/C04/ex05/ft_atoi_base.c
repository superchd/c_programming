/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:26:27 by hchd              #+#    #+#             */
/*   Updated: 2021/03/16 10:33:26 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	is_base(char str, char *base)
{
	int	cnt;

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
	int	i;
	int	j;

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
	int	answer;

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
	while (base[index])
	{
		if (str == base[index])
			break ;
		index++;
	}
	while (clear_str[i])
	{
		if (!is_base(clear_str[i], base))
			len++;
		i++;
	}
	return (index * power(base_len, i - len - 1));
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sum;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	sum = 0;
	base_len = check_base(base);
	if (base_len == -1)
		return (0);
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		++str;
	while (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign *= -1;
	while (*str)
	{
		if (is_base(*str, base) == false)
			break ;
		sum += transfer_to_int(*str, str, base, base_len);
		str++;
		i++;
	}
	return (sign * sum);
}
