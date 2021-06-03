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
	int _x;
	int _y;
	int _width, _height;
	vector<vector<int> > _numbers;
public:
	Board(int width, int height) : _width(width), _height(height) {}
	Board(vector<vector<int> > numbers) : _numbers(numbers) {}
	void mark();
	void point();
};

void Board::point()
{
	_x = 0;
	_y = 0;
	for (int i = 0; i < size() ; i++)
	{
		if (_numbers[0][i] % 2 == 0)
			_x++;
		else
			_y++;
	}
}

void Board::mark()
{
	ostringstream buf;

	int cnt;

	int max = *max_element(_numbers[1].begin(), _numbers[1].end());
	char prev = buf.fill('-');
	buf << "+-" << setw(max) << "" << "-+" << endl;
	char pres = buf.fill(' ');
	for (int i = 0 ; i < _height ; i++)
	{
		if (i == _numbers[1][1])
		{
			buf << "| " << setw(_numbers[1]) << " |" << endl;
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
	vector<<int> >numbers;

	cin >> width >> height;
	numbers[0].push_back(width);
	numbers[0].push_back(height);

	while (cin >> num)
	{
		numbers[1].push_back(num);
	}
	Board(numbers);

}
