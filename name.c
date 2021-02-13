#include <stdio.h>
#include <string.h>

#define length 64
void reverse_name( char* name);

int main(){

//	char name[100] ; //공백이 있는 인풋을 아주 잘받는방법은 무엇이 있을까??
//	char* p;

//	scanf("%s", name); //공백이 있기 떄문에 다르게 인풋을 받아야 할것같다
	
//	p = name;
//

	char* name = "cristiano ronaldo";

	
	reverse_name (name);

	return 0;
}

void reverse_name( char* name){

	char first[length];
	char last[length];
	int i;
	int j;

	

		for( i = 0; *name == '\0' ;i++){

			
			first[i] = *name++;
			
		}	
		

		for( j = 0; *(name++) == '\0' ; i++){

			last[j] = *name;
		}	

		

	
	
	printf("%s %s",last,first);

}
		



		








