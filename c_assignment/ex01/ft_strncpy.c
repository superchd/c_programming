/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:12:14 by hchd              #+#    #+#             */
/*   Updated: 2021/03/09 22:00:05 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		index;
	char	*pdest;

	index = 0;
	pdest = dest;
	while (index < n)
	{
		*(dest + index) = *(src + index);
		index++;
	}
	return (pdest);
}
