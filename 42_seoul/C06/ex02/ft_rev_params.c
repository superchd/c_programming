/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 23:17:34 by hchd              #+#    #+#             */
/*   Updated: 2021/03/15 18:20:25 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(char **p, char **q)
{
	char *temp;

	temp = *p;
	*p = *q;
	*q = temp;
}

void	rev_params(int number, char **program)
{
	int	i;
	int	j;

	i = 0;
	while (i < number / 2)
	{
		swap(&program[i], &program[number - i]);
		++i;
	}
}

void	write_argv(int argc, char **program_name)
{
	int	index;
	int	j;

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
}

int	main(int argc, char **argv)
{
	int	index;
	int	j;
	char	*program[argc];

	index = 0;
	while (index < argc)
	{
		program[index] = argv[index];
		++index;
	}
	rev_params(argc, program);
	write_argv(argc, program);
	return (0);
}
