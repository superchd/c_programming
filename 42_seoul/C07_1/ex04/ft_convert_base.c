/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:36:53 by hchd              #+#    #+#             */
/*   Updated: 2021/03/17 02:29:33 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
bool	is_base(char str, char *base);
int		check_base(char *base);

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
			len++;
		i++;
	}
	return (index * power(base_len, i - len - 1));
}

int		ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sum;
	int	sign;
	
	sign = 1;
	sum = 0;
	base_len = check_base(base);
	if (base_len == -1 || base_len == 1 || base_len == 0)
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
	}
	return (sign * sum);
}

char	*ft_itoa_base(long long num, char *base_to, char **string, int cnt)
{
	int			base_len;
	long long	len;
	char		*convert_char;

	base_len = check_base(base_to);
	if (base_len == -1 || base_len == 1 || base_len == 0)
		return ("a");
	if (num < 0)
	{
		ft_itoa_base(-num, base_to, string, cnt);
	}
	else
	{
		if (num > base_len - 1)
			ft_itoa_base(num / base_len, base_to, string, cnt - 1);
		(*string)[cnt] = base_to[num % base_len];
	}
	return (*string);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int cnt;
	int len;
	char *answer;
	char *string;
	long long	changed_nbr;
	long long	replace;
	cnt = 0;
	len = check_base(base_to);
	changed_nbr = (long long)(ft_atoi_base(nbr, base_from));
	// changed_nbr  이 음수면 ... "-" 추가 
	replace = changed_nbr;
	if (len == -1 || len == 1 || len == 0)
		return ("a");
	while (changed_nbr >= len - 1)
	{
		changed_nbr /= len;
		cnt++;
	}
	string = (char *)malloc(sizeof(char) * (cnt + 1));
	ft_itoa_base(replace, base_to, &string, cnt);
	return (string);
}

