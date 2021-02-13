#include <stdio.h>
#include <string.h>

double compute_average_word_length(const char* sentence);

int main(){

	const char* sentence = "under my skin";
	
	double average;

	average = compute_average_word_length ( sentence);

	printf("%f", average);

	return 0;
}

double compute_average_word_length(const char* sentence){
	
	int space = 1;
	int sum = 0;
	double average ;

	while( *sentence == '\n'){

		for( ; *sentence ; sentence++){

			sum ++;
		}

		space++;

	}

	average = sum/space;

	return average ;



}






