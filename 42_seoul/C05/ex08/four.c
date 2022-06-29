/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchd <hchd@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:11:20 by hchd              #+#    #+#             */
/*   Updated: 2021/03/13 00:59:26 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int	find_row_location(int column, bool table[][4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (table[i][column] == true)
			return (i);
		i++;
	}
	return (0);
}
bool	is_valid_queens(int row, int column, bool table[][4])
{  //동일한 행, 그리고 대각선에 queen이 있는지 확인
	int i;
	int diff;
	int column_id = column;

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

void	print_table(bool table[][4])
{
	int i;
	int j;
	char answer;

	i = 0;
	j = 0;
	while (j < 4)
	{
		while (i < 4)
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
}

void	make_table(int row, int column, bool table[][4])
{
	if (column == 4)
	{
		print_table(table);
		return ;
	}
	else
	{
		while (row < 4)
		{
			table[row][column] = true;
			if (is_valid_queens(row, column, table))
			{
				make_table(0, column + 1, table);
			}	
			else
				table[row][column] = false;
			row++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int i;
	int j;
	int index;
	int	table[4];
	
	i = 0;
	j = 0;
	index = 0;
	while (i < 4)
	{
		table[i] = 0;
	}
	while (index < 4)
	{
		make_table(index, 0, table);
		index++;
	}
	return (0);
}

int main()
{
	ft_ten_queens_puzzle();
	return 0;
}
