/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chanlee.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:11:20 by hchd              #+#    #+#             */
/*   Updated: 2021/03/13 01:30:45 by hchd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
int	find_row_location(int column, bool table[][10])
{
	int i;
	i = 0;
	while (i < 10)
	{
		if (table[i][column] == true)
			return (i);
		i++;
	}
	return (0);
}
bool	is_valid_queens(int row, int column, bool table[][10])
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

void	print_table(bool table[][10])
{
	int i;
	int j;
	char answer;
	//i = 0;
	j = 0;
	while (j < 10)
	{
		i = 0; // 추가
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
	//추가
	write(1, "\n", 1);
}

void	make_table(int row, int column, bool table[][10])
{
	if (column == 10)
	{
		print_table(table);
		// 추가
		return ;
	}
	else
	{
		while (row < 10)
		{
			table[row][column] = true;
			if (is_valid_queens(row, column, table))
			{
				make_table(0, column + 1, table);
			//	return ; 여기서 리턴하면 안 되고 로우 하나 추가해서 다시 ㄱㄱ
			}
//			else 다음 칼럼 갔다가 재귀로 돌아오면 해당 [로우][칼럼]은 취소해야 하므로 else없이 항상 false로 바꿔줘야
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
	bool	table[10][10];
	i = 0;
//	j = 0;
	index = 0;
	while (i < 10)
	{
		// j = 0을 여기서 값 부여(j 인덱스는 항상 0부터 시작해야)
		j = 0;
		while (j < 10)
		{
			table[i][j] = false;
			j++;
		}
		i++;
	}
	// while (index < 4)   // make_table 자체에서 로우마다 체크하므로 여기서 인덱스 돌릴 필요 x
	// {
		make_table(0, 0, table);
	// 	index++;
	// }
	return (0);
}

int main()
{
	ft_ten_queens_puzzle();
	return 0;
}
