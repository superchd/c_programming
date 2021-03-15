#include <stdbool.h>
bool	is_base_number(char str, char *base)
{
	int cnt;

	cnt = 0;
	while (*base)
	{
		if (str == *base++)
			cnt++;
	}
	if (cnt == 1)
		return (true);
	else
		return (false);
}

int	power(int n, int m)
{
	int answer;

	answer = 1;
	if (m == 0)
		return (1);
	else
	{
		answer = n * power(n, m - 1);
	}
	return (answer);
}

int	transfer_to_int(char str, char *clear_str, char *base, int base_len)
{
	int num;
	int	index;
	int len;

	index = 0;
	while (str != *base)
	{
		base++;
		index++;
	}
	while (is_base_number(*clear_str++, base))
		len++;
	num = index * power(base_len, len - 1);
	return (num);
}

int main(void)
{
	int k;
	k = transfer_to_int('3',"12345","0123456789",10);
	return 0;
}
