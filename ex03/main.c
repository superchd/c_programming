#include <stdio.h>
#include <stdlib.h>
int ft_atoi(char *str);
int main(void)
{
	int k;
	int j;

	k = ft_atoi("     -----+32    3452");
	j = atoi("     -----+32    3452");
	printf("%d\n", k);
	printf("%d\n" , j);
	return 0;
}

