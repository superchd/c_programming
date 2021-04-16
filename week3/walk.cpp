#include <cstdio>
#include <stdbool.h>

bool	is_odd(int num)
{
	if (num % 2 == 1)
		return (true);
	else
		return (false);
}

void	walk(int *arr, int index, int cnt, int *x, int *y)
{

	if (cnt == 0)
		return ;
	else
	{
		if (is_odd(arr[index]))
			y += 1;
		else
			x += 1;
		walk(arr, index + 1, cnt - 1, x, y);
	}
}


int	main(void)
{
	int k;
	int arr[100];
	int cnt;
	int i;
	int x;
	int y;

	i = 0;
	cnt = 0;
	x = 0;
	y = 0;
	while (scanf("%d", &k) == 1)
	{
		arr[i++] = k;
		cnt++;
	}
	walk(arr, 0, cnt, &x, &y);
	printf("%d\n%d", x, y);
	return (0);
}
