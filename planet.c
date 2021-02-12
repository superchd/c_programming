#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char* argv[])
{
	char **p;

	const char* planet[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune","Pluto"};

	int i = 1;

	for (p = &argv[1] ; *p != NULL ; p++)

		if ( *p == planet ){ //**p == * planet이 더 안정적인 설계인가
			printf("%s is planet %d ", **p, i);

		}

		i++;


	return 0;


}
		// planet에 들어가는질 알아야지

