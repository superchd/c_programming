#include <iostream>
#include <cctype>
#include <sstream>
#include <string>

using namespace std;

string maskdigit(string s) {
for (int i = 0; i < s.length(); ++i)
	if (isdigit(s.at(i))) s[i] = '*';
return s;
}
int main(){
	int k = 0;
	string s;
	string line;
	getline(cin, line);
	istringstream ins(line);
	while (ins >> s)
	{
		cout << s << endl;
	}
}
