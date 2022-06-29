/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:39:30 by hchd              #+#    #+#             */
/*   Updated: 2021/03/10 09:53:53 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void	hexadecimal(char str)
{
	char *hexa;
	unsigned long decimal;

	decimal = (unsigned long)str;
	hexa = "0123456789abcdef";
	if (decimal > 97)
	{
		if (decimal > 15)
			hexadecimal(decimal / 15 - 1);
	}
	else
	{
		if (decimal > 15)
			hexadecimal(decimal / 15);
	}
	decimal %= 16;
	decimal = hexa[decimal];
	write(1, &decimal, 1);
}

void	print_first_word_address(char *first_str)
{
	long long 	first_str_address;
	char		*str;
	first_str_address = (long long)first_str;
	str = (char *)first_str_address;
	hexadecimal(first_str_address);
}

void	print_string(char *str)
{
	int		index;
	char	dest[16];

	index = 0;
	while (index < 16)
	{
		dest[index] = *str;
		write(1, &dest[index], 1);
		str++;
		index++;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;
	long long			long_addr;
	char 				*changed_char;

	i = 0;
	changed_char = (char *)addr;
	while (i < size / 16)
	{
		j = 0;
		print_first_word_address(changed_char);
		write(1, ": ", 2);
		while (j < 16)
		{
			hexadecimal(*changed_char++);
			j++;
			hexadecimal(*changed_char++);
			j++;
			write(1, " ", 1);
		}
		print_string(paddr);
		write(1, "\n", 1);
		i++;
	}
}

int main(void)
{
	char a[] = "Bonjour les amin ches...c est fo u,tout.ce qu on peut faire avec...print_memory....lol.lol.  .";

	ft_print_memory(a, 96);
	return 0;
}
