#include <stdio.h>
#include <string.h>
#include <ctype.h>
int read_line(char str[] ,int n);

int main(){
	int n;
        char str[100];
	scanf("%d",&n);
	read_line(str,5);
	printf("%s",str);
	return 0;
}

int read_line ( char str[] , int n){
	int ch, i = 0 ;
	
	while((ch = getchar()) != '\n')
		if(i<n)
			str[i++] =toupper(ch);
			
	str[i++] = '\0';
	return i;
}
