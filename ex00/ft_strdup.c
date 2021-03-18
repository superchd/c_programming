/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:45:48 by hchd              #+#    #+#             */
/*   Updated: 2021/03/15 16:31:17 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		++str;
		++len;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strdup(char *src)
{
	char *array;
	char *result;

	array = (char *)malloc(ft_strlen(src) + 1);
	if (!array)
		return (0);
	ft_strcpy(array, src);
	return (array);
}
