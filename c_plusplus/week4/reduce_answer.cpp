#include <cstdio>
#include <vector>
#include <stdio.h>
using namespace std;

class intbag
{
	public:
		vector<int> ns;
		
		int reduce()
		{
			int sz = ns.size();
			int temp;
			intbag newbag;
			if (sz == 1)
				return ns[0];

			else
			{
				for (int i = 0; i < sz - 1; i++)
				{

					temp = (ns[i] + ns[i + 1]) % 100;
					newbag.ns.push_back(temp);
				}
				return newbag.reduce();
			}
		}

};

int main(void)
{
	intbag k;
	int n;

	while (scanf("%d", &n) == 1)
	{
		k.ns.push_back(n);
	}
	printf("%d", k.reduce());
}
