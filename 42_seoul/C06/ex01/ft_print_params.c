/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 00:08:42 by hchd              #+#    #+#             */
/*   Updated: 2021/03/12 23:16:11 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;
	int	j;
	char	*program_name[argc];

	index = 1;
	while (index < argc)
	{
		program_name[index] = argv[index];
		++index;
	}
	index = 1;
	while (index < argc)
	{
		j = 0;
		while (*(program_name[index] + j))
		{	
			write(1, program_name[index] + j, 1);
			++j;
		}
		write(1, "\n", 1);
		++index;
	}
	return (0);
}
