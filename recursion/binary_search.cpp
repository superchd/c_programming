#include <cstdio>
#include <iostream>
#include <array>
#include <vector>
#define N 100

using namespace std;

int		n, question;
vector<int>	finder;
array<int, N>   my_arr;

int	binary(int start, int end, int my_goal){
// start 부터 end 까지중 my_goal를 찾으면, 멈추고, 그 my_goal가 몇번째에 있는 수인지 return 한다.
	int mid = (start + end) / 2;

	if (start > end) {
		return (-1);}
	else if (my_goal == my_arr[start]) {
		return (start);}
	else if (my_goal == my_arr[end]) {
		return (end);}
	else {
		if (my_goal > my_arr[mid]) {binary(mid, end, my_goal);}
		else 			   {binary(start, mid, my_goal);} 
	}
	return start;

}

void	my_input(void){

	int num;

	cin >> n;
	cin >> question;
	for (int i = 0; i < n; i++){
		cin >> num;
		my_arr[i] = num;
	}
	for (int j = 0; j < question; j++){
		cin >> num;
		finder.push_back(num);}
	return ;
}

void	my_sol(void) {

	for (auto s : finder){
		int inx = binary(0, n - 1, s);

		if (inx == - 1) {
			cout << "NO" << endl;}
		else {
			cout << "YES" << endl;}
	}
}

int main(void){
	my_input();
	my_sol();

	return 0;
}
