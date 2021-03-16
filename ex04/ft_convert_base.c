/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:36:53 by hchd              #+#    #+#             */
/*   Updated: 2021/03/16 02:10:10 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sum;
	int sign;
	int i;

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
			return (sign * sum);
		sum += transfer_to_int(*str, str, base, base_len);
		i++;
		str++;
	}
	return (sign * sum);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int num;
	char *answer;

	num = ft_atoi_base(nbr, base_from);
	answer = ft_itoa_base(nbr, base_to);

	

}

