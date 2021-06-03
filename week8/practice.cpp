#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stdbool.h>

using namespace std;

class Board
{
	public:
		bool is_odd(int num);
		void walk(int *arr, int index, int cnt, int *x, int *y);
		void destination(void);
		void graph(int x, int y);
		int a;
		int b;
		
	private:
		vector<int> sizes;
		vector<int> points;
		int arr[100];
		

};

int main(void)
{
	Board map;
	map.destination();
	return 0;
}

bool	Board::is_odd(int num)
{
	if (num % 2 == 1)
		return (true);
	else
		return (false);
}

void	Board::walk(int *arr, int index, int cnt, int a, int b)
{

	if (cnt == 0)
	{
		return ;
	}
	else
	{
		if (is_odd(arr[index]))
			b += 1;
		else
			a += 1;
		walk(arr, index + 1, cnt - 1, a, b);
	}
}

void  Board::graph(int x, int y)
{
	
	ostringstream buf;

	int cnt;

	char prev = buf.fill('-');	 
	buf << "+-" << setw(x-2) << "" << "-+" << endl;
	char pres = buf.fill(' ');			
	for (int i = 0 ; i < y ; i++)
	{	
		if (i != b)
	 		buf << "| " << setw(x) << " |" << endl;
		else
	 		buf << "| " << setw(a) << "." << setw(x-a) <<  " |" << endl;
	}
	char prev1 = buf.fill('-');
	 buf << "+-" << setw(x-2) << "" << "-+" << endl;
	 buf.fill(prev1);
	 cout << buf.str();
}

void	Board::destination(void)
{
	int k;
	int cnt;
	int i;
	int x;
	int y;

	i = 0;
	cnt = 0;
 	a = 0;
	b = 0;
	cin >> x >> y;
	sizes.push_back(x);
	sizes.push_back(y);

	while (cin >> k)
	{
		arr[i++] = k;
		cnt++;
	}
	walk(arr, 0, cnt, a, b);
	graph(x, y);
}
