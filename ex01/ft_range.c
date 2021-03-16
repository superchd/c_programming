/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:34:10 by hchd              #+#    #+#             */
/*   Updated: 2021/03/15 16:43:02 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int bound;
	int *array;

	i = 0;
	bound = max - min;
	if (bound < 0)
		bound *= -1;
	array = (int *)malloc((bound + 1) * sizeof(int));
	if (!array)
		return (0);
	while (i < bound + 1)
	{
		array[i] = min;
		i++;
		min++;
	}
	return (array);
}
