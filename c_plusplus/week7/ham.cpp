#include <cstdlib>
#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

/**************************************************************************************/
class Hamstring {
    public:
        void read_strings();
        void read_lengths();
	int find_distance();
    private:
        vector<string> strs;
	vector<int> lengths;
	vector<int> counts;
};

void Hamstring::read_strings()
{
	int i;
	string n;

    for (i = 0 ; i < 2; i++) {
	    cin >> n;
        strs.push_back(n);
    }
}


void Hamstring::read_lengths()
{
	int n;
	int i;
	n = 0;
    for (i = 0; i < 2 ; i++) {
        n = strs[i].length();
        lengths.push_back(n);
    }
}

/*************************************************************************/
/*************************************************************************/

int Hamstring::find_distance()
{
	int k;
	int count;

	count = 0;
	string changed = "";
	string temp;
	k = strs[0].length() - strs[1].length();
	if (k < 0)
	{
		temp = strs[0];
		strs[0] = strs[1];
		strs[1] = temp;
		k *= -1;
	}
		
	for (int i = 0; i <= k ; i++)
	{
		for (int j = 0; j < i; j++)
		{
			changed += '0';
		}
		changed += strs[1];
		for(int i=0; strs[0][i]!=0; i++)
		{
        		if((strs[0][i] != changed[i]) && changed[i] != '0' && changed[i] != ' ' && changed[i] != '\0')
            			count++;
		}
		counts.push_back(count);
		count = 0;
		changed = "";
	}
	/*
	for(int i=0; strings[0][i]!=0; i++)
	{
        	if((strings[0][i] != changed[i]) && changed[i] != ' ')
            		count++;
	}
	*/
	int min = *min_element(counts.begin(), counts.end());
	return min;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
int main(void) 
{

	int answer;

	Hamstring np;
	np.read_strings();
	np.read_lengths();
	answer = np.find_distance();
    
    //finding Hamming distance
      cout<< answer;
    
    return 0;
}
