#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*make_unit_str(int index)
{
	int	i;
	char	*unit;

	i = 1;
	unit = (char *)malloc(sizeof(char) * (index + 1));
	unit[0] = '1';
	while (--index)
	{
		unit[i] = '0';
		i++;
	}
	unit[i] = 0;
	return (unit);
}

int main(void)
{
	char *p;

	p = make_unit_str(8);
	return 0;
}
