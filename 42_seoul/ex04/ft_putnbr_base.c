/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:34:43 by hchd              #+#    #+#             */
/*   Updated: 2021/03/09 15:07:20 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*(base + i))
	{
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (-1);
			if (*(base + i) == '-' || *(base + i) == '+')
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

int	process_minimum(int len, char *base)
{
	int	nbr;

	write(1, "-", 1);
	nbr = 147483648;
	return (nbr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	char	convert_char;

	len = check_base(base);
	if (len == -1)
		return ;
	if (nbr == -2147483648)
	{
		process_minimum(len, base);
		ft_putnbr_base(2, base);
		ft_putnbr_base(147483648, base);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	else
	{
		if (nbr > len - 1)
			ft_putnbr_base(nbr / len, base);
		convert_char = base[nbr % len];
		write(1, &convert_char, 1);
	}
}
