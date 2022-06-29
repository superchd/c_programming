/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:28:35 by hchd              #+#    #+#             */
/*   Updated: 2021/03/09 22:04:13 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	char *pstr;

	pstr = str;
	while (*str)
	{
		if (*str >= 65 && *str <= 90)
		{
			str++;
		}
		else if (*str >= 97 && *str <= 122)
		{
			str++;
		}
		else
			return (0);
	}
	return (1);
}
