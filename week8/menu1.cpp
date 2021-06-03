#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Menu
{
	private:
		vector<int> lengths;
		vector<string> words;
	public:
		ostringstream buf;
		void read_strings();
		void print();
};

void Menu::read_strings()
{
	int cnt;
	string word;

	while (cin >> word)
	{
		cnt = word.length();
		lengths.push_back(cnt);
		words.push_back(word);
	}
}

void Menu::print(ostream& os) 
{   
    print1();
}   

void Menu::print1()

{
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

int main()
{
	Menu menu;

	menu.read_strings();
	menu.print();
	return (0);
}
