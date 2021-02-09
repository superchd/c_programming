#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 64
#define MAX_COUNT 100

void smallest_word(char* (pointer[MAX_COUNT]));

int main(){

	char table[MAX_COUNT][MAX_COUNT];

	char* (ptr[MAX_COUNT]);

	int count ,i, l ;
	//문자열 만드려면 배열을 만들어야하는데 , 배열을 얼마나 많이 만들어야하지?
	for(count = 0; count < MAX_COUNT ; count++){

		printf("Enter a word : ");

		fgets(table[count] , MAX_LENGTH, stdin) ;

		l = strlen(table[count]);

		if( l ==5){
		// 마지막 널문자도 고려해야 하기 때문에 크기는 5로 받는다.
			break;
		}
        }

	for(int j=0;j<count;j++){
		ptr[j] = table[j];
	}


	smallest_word(ptr);



	for(i=0 ; i<++count ; i++){

		printf("%s" , table[i]);
	
	}



return 0;

}

void smallest_word(char* (pointer[MAX_COUNT])){

	int step ,i ;
	char* temp_str;
	
	for(step = 0; step < MAX_COUNT - 1 ; step++){
		for(i=0; i<MAX_COUNT - 1 -step ;i++){

			if(strcmp(pointer[i],pointer[i+1]) > 0){
				temp_str = pointer[i];
				pointer[i] = pointer[i+1];
				pointer[i+1] = temp_str;
			}

		}
	}



	}


