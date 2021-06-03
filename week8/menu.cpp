#include <iostream>
 #include <iomanip>
 #include <sstream>
 #include <string>
#include <vector>
#include <algorithm>

 using namespace std;

int main()
 {
	
	 ostringstream buf;

	 string word;
	 vector<int> lengths;
	 vector<string> words;
	 int cnt;

	 while (cin >> word)
	 {
		 cnt = word.length();
		 lengths.push_back(cnt);
		 words.push_back(word);
	 }

	 int max = *max_element(lengths.begin(), lengths.end());
	 char prev = buf.fill('-');	 
	 buf << "+-" << setw(max) << "" << "-+" << endl;
	char pres = buf.fill(' ');			
	for (string word: words)
	 	buf << "| " << setw(max) << right <<  word << " |" << endl;
	char prev1 = buf.fill('-');
	 buf << "+-" << setw(max) << "" << "-+" << endl;
	 buf.fill(prev1);
	 cout << buf.str();
 }
