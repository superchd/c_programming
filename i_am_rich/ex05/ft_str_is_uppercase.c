/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:29:39 by hchd              #+#    #+#             */
/*   Updated: 2021/03/09 22:16:45 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (*str >= 65 && *str <= 90)
		{
			str++;
		}
		else
			return (0);
	}
	return (1);
}

int main(void)
{
	int k;

	k = ft_str_is_uppercase("AAVFFVD");
	printf("%d\n", k);

	k = ft_str_is_uppercase("asdvfvfbg");
	printf("%d", k);
	return 0;
}
