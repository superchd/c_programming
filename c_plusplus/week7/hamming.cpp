#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <cstdlib>

using namespace std;

int difference(string str1, string str2)
{
	int count = 0;
	for(int i = 0; i < str1.length() ; i++)
	{
		if(str1[i] != str2[i] && str1[i] != '\0' && str2[i] != '\0')
			count++;
	}
	return count;
}

class Hamstring
{
	private:
		string str;
		vector<int> distances;
		vector<int> lengths;
	public:
		Hamstring()
		{
			str = "";
		};
		Hamstring(string word)
		{
			str = word;
		};
		int dist(Hamstring b)
		{
			int count = 0;
			string temp;
			int l1 = str.length();
			int l2 = b.str.length();
			string temp1 = str;
			string temp2 = b.str;
			if (l1 < l2)
			{
				temp1 = b.str; 
				temp2 = str;
			}
			for(int i = 0; i <= abs(l1 - l2) && i <= temp2.length(); i++)
			{
				count = difference(temp1.substr(i), temp2);
				distances.push_back(count);
			}
			int min = *min_element(distances.begin(), distances.end());
			return min;
		}
};
// dist에 다 때려박으면 얼마나 쉽냐?ㅋㅋ 하지만.... 이러면 코딩이...
//나의 목표는 dist(A, B)인데 이게 쉽지는 않네.....

int main(void)
{
	int k;
	string s1, s2;
	cin >> s1 >> s2;
	Hamstring A(s1), B(s2);
	k = A.dist(B);
	cout << k << endl;
//	k = dist(A, B);
}
