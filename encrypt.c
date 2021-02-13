#include <stdio.h>
#include <string.h>


#define length 300
#define MAX_WORDS 30
#define MAX_LENGTH 20
void encrypt (char* message, int shift);

int main(){

	char sentence[length] ;

	fgets(sentence , length, stdin);
	
	encrypt(sentence , 3);

	printf("\n");

	return 0;

}

void encrypt (char* message, int shift){

	char* alphabet = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	char *p = alphabet;
	int index = 0;
	
	for( ; *message ; message++){
			
			if( *message == *alphabet++){
				
				printf("%c", *(alphabet+shift-1));
			
				}
			alphabet = p;
			}

		}









