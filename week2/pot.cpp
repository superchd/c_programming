#include <cstdio>

int	power_of_2(int B)
{
	int value;

	value = 1;
	if (B == 1)
		return 2;
	while(value <= B)
	{
		value *= 2;
	}
	return value;
}

int main(void)
{
	int B;
	int k;

	scanf("%d", &B);
	k = power_of_2(B);
	printf("%d", k);	
}
