#include <stdio.h>
#include <string.h>

int main(){
	int num;
	const char* first_digit[] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	int p;

	printf("Enter the number :");
	scanf("%d", &num);

	if( num < 20)
		printf(" this number is tenth");
	
	else{	
		p = num / 10;
		
		printf("%s" , first_digit[p-2]);
	}
	return 0;
}




