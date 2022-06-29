#include <cstdio>
#include <iostream>
#include <array>
#define N 100

using namespace std;

int		n;
array<int, N>   my_arr;

void	my_input(void){

	int num;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num;
		my_arr[i] = num;
	}
	return ;
}

int main(void){
	my_input();

	return 0;



}
