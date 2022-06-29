/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:36:53 by hchd              #+#    #+#             */
/*   Updated: 2021/03/17 18:46:24 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

bool	is_base(char str, char *base);
int	check_base(char *base);
bool	exception(char *base_from, char *base_to);

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

int		transfer_to_int(char str, char *clear_str, char *base, int base_len)
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
			break;
		i++;
	}
	return (index * power(base_len, i  - 1));
}

int		ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sum;
	int	sign;
	
	sign = 1;
	sum = 0;
	base_len = check_base(base);
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		++str;
	while (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign *= -1;
	while (*str)
	{
		if (!is_base(*str, base))
				break;
		sum += transfer_to_int(*str, str, base, base_len);
		str++;
	}
	return (sign * sum);
}

char	*ft_itoa_base(long long num, char *base_to, int cnt, int sign)
{
	int to_len;
	char	*string;
	long long replace;

	replace = num;
	to_len = check_base(base_to);
	while (num > 0)
	{
		num /= to_len;
		cnt++;
	}
	string = (char *)malloc(sizeof(char) * (cnt + 1));
	if (sign == 1)
		string[0] = '-';
	string[cnt] = 0;
	while (cnt - sign > 0)
	{
		string[cnt - 1] = base_to[replace % to_len];
		replace /= to_len;
		--cnt;
	}
	return (string);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int cnt;
	int sign;
	char	*answer;
	long long	changed_nbr;
	long long	replace;

	sign = 0;
	cnt = 0;
	changed_nbr = (long long)(ft_atoi_base(nbr, base_from));
	replace = changed_nbr;
	if (!exception(base_from, base_to))
		return (0);
	if (changed_nbr < 0)
	{
		changed_nbr *= -1;
		replace *= -1;
		cnt += 1;
		sign = 1;
	}
	answer = ft_itoa_base(replace, base_to, cnt, sign);
	return (answer);
}
