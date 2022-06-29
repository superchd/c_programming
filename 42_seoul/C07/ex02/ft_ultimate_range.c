/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:44:07 by hchd              #+#    #+#             */
/*   Updated: 2021/03/15 21:03:33 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int bound;
	int *tmp;

	i = 0;
	bound = max - min;
	*range = (int *)malloc(sizeof(int) * bound);
	tmp = *range;
	if (!*range || bound <= 0)
		return (0);
	while (i < bound + 1)
	{
		tmp[i] = min++;
		i++;
	}
	return (i);
}
