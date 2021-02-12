#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	main(int argc, char* argv[])
{
	char **p;

	const char* planet[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune","Pluto"};

	int i = 0;
        int j ;

	for ( i ; i < argc ; i++)

		for ( j = 0; j < 9 ;j++)

			if ( strcmp( argv[i], planet[j]) == 0)

				printf("%s is planet %d\n", argv[i], i+1);
				return 0 ;

			if ( j == 9)
				printf("%s is not a planet\n", argv[i]);
				return 0;






	return 0;


}
		// planet에 들어가는질 알아야지

