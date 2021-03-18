/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:19:00 by hchd              #+#    #+#             */
/*   Updated: 2021/03/18 00:36:33 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


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

void	ft_strcat_sep(char *dest, char *src, char *sep, int *end, int size)
{
	/*
	if (!*src)
		return ;
		*/
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	if (*end < size - 1 )
	{
		while (*sep)
		{
			*dest = *sep;
			++dest;
			++sep;
		}
	}
	*end += 1;
}

char	*exception(void)
{
	char *array;

	array = (char *)malloc(1);
	array[0] = 0;
	return (array);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	end;
	int	len;
	char	*array;

	i = 0;
	len = 0;
	end = 0;
	if (size <= 0)
		return (exception());
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
		ft_strcat_sep(array, strs[i], sep, &end, size);
		i++;
	}
	return (array);
}
