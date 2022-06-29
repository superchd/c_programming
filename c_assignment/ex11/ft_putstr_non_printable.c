/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:14:40 by hchd              #+#    #+#             */
/*   Updated: 2021/03/10 02:22:34 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char *hex;
	char first;
	char second;

	if (*str != '\0')
	{
		hex = "0123456789abcdef";
		first = hex[*str / 16];
		second = hex[*str % 16];
		write(1, "\\", 1);
		write(1, &first, 1);
		write(1, &second, 1);
	}
}
