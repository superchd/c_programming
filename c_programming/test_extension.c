#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
bool test_extension(char* file_name, char* extension);

int main()
{	


	 char *s1 = malloc(sizeof(char) * 10);    // char 10개 크기만큼 동적 메모리 할당

	     printf("문자열을 입력하세요: ");
	     scanf("%s", s1);      // 표준 입력을 받아서 메모리가 할당된 문자열 포인터에 저장

	 char *s2 = malloc(sizeof(char) * 10);    // char 10개 크기만큼 동적 메모리 할당

    	     printf("문자열을 입력하세요: ");
    	     scanf("%s", s2);      // 표준 입력을 받아서 메모리가 할당된 문자열 포인터에 저장    
	bool p ; 
	
	p = test_extension(s1,s2);
	printf(p ? "true" : "false"); 
	return 0;
}

bool test_extension(char* file_name,char* extension){

	while(*(file_name++) != '\0'){

		if(*file_name == '.'){

			// 여러문자를 어떻게 비교할것인가??
		//	for(;*file_name == '\0' ;file_name++){

			        file_name += 1;

				if(strcmp(file_name , extension++) != 0){
					
					printf("NOT EQUAL.\n") ;
					return false;
				}

				printf("EQUAL.\n");
				return true;
			}

		}

	}
	








