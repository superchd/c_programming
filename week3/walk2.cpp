#include <iostream>
#include <stdio.h>

bool	is_odd(int n)
{
	if (n % 2 != 0)
		return true;
	return false;
}

// 인자를 배열로 할까 아니면 그냥 int로 할까??

void	move(int sz, int *arr, int i)
{
	static int x = 0 , y = 0;

	if (sz == 0)
		printf("%d %d", x ,y);
	else
	{
		if (is_odd(arr[i]))
			x++;
		else
			y++;
		move(sz - 1, arr, i + 1 );
	}
}

int	main(void)
{
	int arr[100];
	int n;
	int sz = 0;
	int x = 0;
	int y = 0;

	while (scanf("%d", &n) == 1)
	{
		arr[sz++] = n;
	}
	move(sz, arr, 0);
}
