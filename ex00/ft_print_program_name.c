/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:59:53 by hchd              #+#    #+#             */
/*   Updated: 2021/03/11 00:06:43 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	index;
	char	*program_name;

	index = 0;
	program_name = argv[0];
	while (*(program_name + index))
	{
		write(1, (program_name + index), 1);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}
