#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{	
	char str[100];

	int i;

	for (i = 0; i < argc; i++){
		str[i] = *argv[i];
	}

	for(i ; i > 0; i--)
		printf("%c",str[i]);

	return 0;

}

