/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:20:28 by hchd              #+#    #+#             */
/*   Updated: 2021/03/10 15:40:53 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long i;

	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	long long i;

	i = 0;
	while (nb++)
	{
		if (ft_is_prime(nb) == 0)
		{
			break ;
		}
	}
	return (nb);
}
