/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:01:44 by hchd              #+#    #+#             */
/*   Updated: 2021/03/10 02:19:45 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int cnt;

	cnt = 0;
	while (cnt < size - 1)
	{
		if (*src)
		{
			*dest++ = *src++;
		}
		cnt++;
	}
	*dest = '\0';
	return (cnt);
}
