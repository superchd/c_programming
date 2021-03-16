/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:19:00 by hchd              #+#    #+#             */
/*   Updated: 2021/03/16 01:36:18 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	g_final_sep;

g_final_sep = 0;

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		++str;
		++len;
	}
	return (len);
}

void	ft_strcat_sep(char *dest, char *src, char *sep)
{
	if (!*src)
		return ;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	while (*sep)
	{
		*dest = *sep;
		++dest;
		++sep;
	}
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	char	*to_find;
	char	*sum;
	char	*array;
	int	len;

	i = 0;
	len = 0;
	if (size <= 0)
	{
		array = (char *)malloc(1);
		array[0] = 0;
		return (array);
	}
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	array = (char *)malloc((size - 1) * ft_strlen(sep) + len + 1);
	if (!array)
		return (0);
	i = 0;
	while (i < size)
	{
		ft_strcat_sep(array, strs[i], sep);
		i++;
	}
	return (array);
}
