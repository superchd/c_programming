#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MAX_CARDS 5
#define MAX_SUITS 4
#define MAX_RANKS 13

int	main(void)
{
	int i;
	i = 0;
	int SUIT = 0;
	int RANK = 0;
	bool in_hand[MAX_SUITS][MAX_RANKS] = "false";
	char selects[5][2];

	srand(time(NULL));

	for (i;i < 5;i++)
                
		SUIT = rand() % 4;
		RANK = rand() % 13;

		scanf ("%d%d", &SUIT, &RANK);

		if (SUIT < 4 && SUIT >= 0 ){
			if (RANK < 13 && RANK >= 0){
				if(in_hand[SUIT][RANK] = "true"){
					printf("Duplicated card");
					break;}
				else{
					in_hand[SUIT][RANK] = "true";}}
					
			else{
				printf("Retry");
				break;}}

		else{ 
			printf("Retry");
			break;}

	
	return 0;
}




			





		
