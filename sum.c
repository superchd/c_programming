#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int i = 0;
	int sum = 0;

	for(i; i < argc -1 ; i++)

		sum += atoi(argv[i]);

	printf("%d" , sum);

	return 0;
}
