#include <stdio.h>
#include <string.h>
#include <ctype.h>

void get_extension (const char* file_name , char* extension);

int main(){
	
	const char* file_name = "Superchd.word";

	char extension[100];

	get_extension ( file_name , extension);

	printf("%s", extension);

	return 0;
}

void get_extension(const char* file_name, char* extension){


	while (*file_name++ != '\n'){

		if( *file_name == '.'){

		//	strcpy(extension++ , file_name); 어짜피 '.' 이후로 시작하는 다음주소만 따오면 되니까 extension ++ 할필요가 없지롱
			strcpy(extension, file_name);
			return;
		}

	}
	strcpy(extension,"");

}



		



