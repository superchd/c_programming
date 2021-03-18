/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:57:44 by hchd              #+#    #+#             */
/*   Updated: 2021/03/18 09:15:07 by hchd             ###   ########.fr       */
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
/*
char *ft_strjoin2(char *strs, char *sep)
{
	int	i;
	int end;
	int len;
	int sep_len;
	char	*sum;
	char	*array;

	i = 0;
	len = 0;
	end = 0;
	sep_len = ft_strlen(sep);
	if (size <= 0)
	{
		array = (char *)malloc();
		array[0] = 0;
		return (array);
	}
	while ()
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
*/
char	*find_charset(char *str, char *charset)
{
	while (*str)
	{
		while (*charset)
		{
			if (*str == *charset)
				return (str);
			charset++;
		}
		str++;
	}
	return (0);
}

int	correspond(char *str, char *charset)
{
	int correct;
	char *original;

	correct = 0;
	original = str;
	while (*charset)
	{
		str = original;
		while (*str)
		{
			if (*charset == *str)
				correct++;
			str++;
		}
		charset++;
	}
	return (correct);
}
// 얼마나 charset과 겹치는게 있을까? 이것도 확인

void	ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char *find;
	char **answer;

	int cnt;
	int correct;
	int index;

	index = 0;
	cnt = 0;
	correct = correspond(str, charset);
	answer = (char **)malloc(sizeof(char *) * (correct + 1));
	while (*str)
	{
		find = find_charset(str, charset);	
		if (find_charset(str, charset) != 0 && find != str)
		{
			answer[index] = (char *)malloc(sizeof(char) * (find - str + 1));
			if (!answer[index])
				return (0) ;
			ft_strncpy(answer[index], str, find - str + 1);
			index++;
		}
		if (find == 0 && *str != 0)
		{
			 
			answer[index] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
			ft_strncpy(answer[index], str, ft_strlen(str) + 1);
		}	
		str++;
	}
	return (answer);
}
