#include <cstdio>
#include <vector>
#include <stdio.h>

using namespace std;

class intbag
{
	private:
		vector<int> bags;
		vector< vector<int> > temps;

	public:
		void reduce();
		void read_int();

};

void intbag::read_int()
{
	int n;

	while (scanf("%d", &n) == 1)
	{
		bags.push_back(n);
	}
}

void intbag::reduce()
{
	int i = 0;
	int j = 0;
	int temp = 0;

	temps.push_back(bags);
	while (i < bags.size())
	{
		while (j < temps[i].size())
		{
			temp = (temps[i][j] + temps[i][j+1]) % 100;
			temps[i].push_back(temp);
			j++;
		}
		i++;
	}

	printf("%d", temps[i][j]);
}

int main(void)
{
	intbag t;

	t.read_int();
	t.reduce();
}

