/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:37:45 by hchd              #+#    #+#             */
/*   Updated: 2021/03/15 14:50:35 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int product;

	product = 1;
	if (nb < 0)
		return (0);
	while (nb != 0)
	{
		product *= nb;
		nb--;
	}
	return (product);
}
