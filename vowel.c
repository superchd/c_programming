#include <stdio.h>
#include <string.h>

int compute_vowel_count( const char* sentence);

int main(){

	char str[10] ;

	int n;

	scanf("%s", str);

	n = compute_vowel_count(str);

	printf("%d" , n);

	return 0;
}

int compute_vowel_count(const char* sentence){

	char* vowel = "aeiou";
        char* p = vowel;
	int count = 0 ;

	for(sentence ; sentence == NULL ; sentence++)
		for(vowel ; vowel ==  NULL ; vowel++)
			if(*sentence == *vowel);
			count ++;
			vowel = p;
	return count;

}

