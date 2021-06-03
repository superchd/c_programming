#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

class Board: public vector<vector<int> > // 여기서 점도 print도 하구, board 판도 그리구 다 해야함!! 
	     // 무엇을 Board의 input으로 받아야 할까 ??
	     // 왜 vector<vector<int>> 의 subclass 일까?? 
{
private:
	int _width, _height;
	vector<int> _numbers;
public:
	Board(int width, int height) : _width(width), _height(height) {}
	Board(vector<int> numbers) : _numbers(numbers) {}
	void mark();
};

void Board::mark()
{
	ostringstream buf;

	int cnt;

	int max = *max_element(_numbers.begin(), _numbers.end());
	char prev = buf.fill('-');
	buf << "+-" << setw(max) << "" << "-+" << endl;
	char pres = buf.fill(' ');
	for (int i = 0 ; i < _height ; i++)
	{
		if (i == _numbers[1])
		{
			buf << "| " << setw(_numbers[0]) << " |" << endl;
		}
		else
		{
			buf << "| " << setw(max) << " |" << endl;
		}
	}
	char prev1 = buf.fill('-');
	buf << "+-" << setw(max) << "" << "-+" << endl;
	buf.fill(prev1);
	cout << buf.str();
}

int main()
{
	int width;
	int height;
	int num;
	int x = 0;
	int y = 0;
	vector<int> numbers;

	cin >> width >> height;
	Board(width, height);
	while (cin >> num)
	{
		if (num % 2 == 0)
			x++;
		else
			y++;
	}
	numbers.push_back(x);
	numbers.push_back(y);
	Board(numbers);
}
