#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	
	char str[100];
	
	int n;

	char* replace = "foo";

	scanf("%d", &n);

	read_line(str , n);

	censor(str);
	
	printf("",);

	return 0;
}


int read_line(char str[] ,int n){
	char ch;char ch;
	int i = 0;
	while((ch = getchar()) != '\n'){
		if(i< n){
			str[i++] = ch;

		}
	}
	str[i] ='\0';	
}

char* censor(char* replace ){
	
	// 특정 문자열을 찾는다라 어떻게 찾으면 될까???
	//모르겠는데 ...
	



