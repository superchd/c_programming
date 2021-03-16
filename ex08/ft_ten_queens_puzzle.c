/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:11:20 by hchd              #+#    #+#             */
/*   Updated: 2021/03/15 15:28:28 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

int		find_row_location(int column, bool table[][10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (table[i][column] == true)
			return (i);
		i++;
	}
	return (0);
}

bool		is_valid_queens(int row, int column, bool table[][10])
{
	int	i;
	int	diff;
	int	column_id;

	column_id = column;
	i = 0;
	if (column == 0)
		return (true);
	while (i < column_id)
	{
		diff = find_row_location(i, table) - row;
		if (diff < 0)
			diff *= -1;
		if (diff == 0 || diff == column_id - i)
			return (false);
		i++;
	}
	return (true);
}

void		print_table(bool table[][10])
{
	int	i;
	int	j;
	char	answer;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (table[i][j] == true)
			{
				answer = i + '0';
				write(1, &answer, 1);
			}
			i++;
		}
		j++;
	}
	write(1, "\n", 1);
}

int		make_table(int row, int column, bool table[][10])
{
	int	cnt;

	cnt = 0;
	if (column == 10)
	{
		print_table(table);
		cnt++;
		return (cnt);
	}
	else
	{
		while (row < 10)
		{
			table[row][column] = true;
			if (is_valid_queens(row, column, table))
				make_table(0, column + 1, table);
			table[row][column] = false;
			row++;
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int	i;
	int	j;
	bool	table[10][10];

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			table[i][j] = false;
			j++;
		}
		i++;
	}
	make_table(0, 0, table);
	return (724);
}
