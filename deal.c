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
	int num_cards ;
	int suit;
	int rank;
	const char rank_code [] = {'2','3','4','5','6','7','8'.'9','t','j','k','q','a'};
	const char suit_code [] = {'c','d','h','s'};

	bool in_hand[MAX_SUITS][MAX_RANKS] = {false};
	char selects[5][2];

	srand(unsigned(time(NULL)));

	printf("Enter card numbers.");
	scanf("%d",num_cards);

	while(num_cards > 0){
		suit = rand() % 4 ;
		rank = rand() % 13 ;
		if(!in_hand[suit][rank]){
			in_hand[suit][rank] = "true";
			num_cards--;
		}
	}



	
	return 0;
}




			





		
