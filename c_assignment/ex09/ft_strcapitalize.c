/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:47:19 by hchd              #+#    #+#             */
/*   Updated: 2021/03/10 02:12:15 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		flag(char str)
{
	if (str >= '0' && str <= '9')
		return (0);
	else if (str >= 'a' && str <= 'z')
		return (1);
	else if (str >= 'A' && str <= 'Z')
		return (2);
	else
		return (3);
}

char	*make_upper(char *str)
{
	*str -= 32;
	return (str);
}

char	*make_lower(char *str)
{
	char *qstr;

	qstr = str;
	while (*str)
	{
		if (flag(*str) == 2)
		{
			*str += 32;
			str++;
		}
		else
			str++;
	}
	return (qstr);
}

char	*ft_strcapitalize(char *str)
{
	char *pstr;
	char *copystr;

	make_lower(str);
	pstr = str;
	copystr = str;
	if (flag(*pstr) == 1)
		*pstr++ -= 32;
	while (*pstr)
	{
		if (flag(*pstr++) == 3 && flag(*pstr) != 3)
		{
			if (flag(*pstr) == 1)
				*pstr -= 32;
		}
		pstr++;
	}
	return (copystr);
}
