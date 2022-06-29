#include <stdio.h>
#include <string.h>
#include <ctype.h>

void build_index_url (const char* domain );

int main(){

	const char domain[100] = "knking.com";

	//printf("Enter your domain; ");

	//scanf("%s" , domain);

	char index[100];

	char* p = index;

	build_index_url ( domain);

	

	return 0;
}

void build_index_url (const char* domain ){


	char* initial = "http://www.";
        const char* final = "/index.html";

	strcat(initial , domain);

	strcat(initial,final);

	printf("%s",initial);


}

