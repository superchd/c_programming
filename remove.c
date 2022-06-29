#include <stdio.h>
#include <string.h>

void remove_filename(char* url);

int main(){
	
	char ur[100]= "http://www.knking.com/index.html.";

	char* url = ur;

	remove_filename( url);

	return 0;

}

void remove_filename(char* url){



	while(*(url++) != '/');
 //	while(*(url++) != '/');
       // while(*(url++) != '/');

	while(*(url++) != '\0'){
		strcat(url , "com");
		}

	printf("%s",url);
}



