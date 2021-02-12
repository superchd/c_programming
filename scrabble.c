#include <stdio.h>
#include <string.h>

int compute_scrabble_value(char* word);

int main(){

	char arr[];

	scanf("%s", arr);

	compute_scrabble_value(arr);
	
	return 0;

}

int compute_scrabble_value(char* word)
{	
	const char* scrabble[] = { "aeilnorstu","dg","bcmp","fhvwy","k","jx","qz"};

	//어떻게 이 문자열에 들어가는지 알지?
	`




