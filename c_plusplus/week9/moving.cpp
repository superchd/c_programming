#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

class Point
{
private:
	int _x, _y;
public:
	Point(int x=0, int y=0): _x(x), _y(y) {} 
	int x() { return _x; } 
	int x(int n) {return _x = n;}
	int y() { return _y; }
	int y(int n) {return _y=n;}
};

class MovingPoint: public Point
{
private:
	int _p, _q;
	vector<int> _nums;
public:
	MovingPoint() : MovingPoint({0}, 0 , 0) {}
    MovingPoint(const vector<int> nums, int x , int y ): MovingPoint(_nums, x, y) {}
    void mark(void);
    void calculate();
    int p() { return _p;}
    int q() { return _q;}
};

ostream& operator <<(ostream& out, MovingPoint p) 
{
    return out << "(" << p.x() << ", " << p.y() << ")";
}
// Board라는 클래스가 왜 필요한지를 모르겠다 ............

void MovingPoint::mark(void)
{
	ostringstream buf;

	vector<int> lengths;
	vector<string> words;
	int cnt;
//lengths 값조절해서 사각형 크기 조절하고 
//for 문 돌릴때 적절하게 point 집어 넣으면되지롱~!! 
	char prev = buf.fill('-');
	buf << "+-" << setw(x() - 2) << "" << "-+" << endl;
	char pres = buf.fill(' ');

	for (int i = 0; i < y() ; i++)
	{
		if (i == q() - 1)
			buf << "| " << setw(p()) << "." << setw(x() - p()) << " |" << endl;
		else
			buf << "| " << setw(x()) << " |" << endl;
	}
	char prev1 = buf.fill('-');
	buf << "+-" << setw(x() - 2) << "" << "-+" << endl;
	buf.fill(prev1);
	cout << buf.str();
}

void MovingPoint::calculate()
{
	_p = 0;
	_q = 0;
	for (int i = 0; i < _nums.size() ; i++)
	{
		if (_nums[i] % 2 == 0)
			_p++;
		else
			_q++;
	}
}

int main() 
{
	int x;
	int y;
	int z;
	vector<int> nums;
	MovingPoint pt;
	cin >> x >> y;
	while (cin >> z)
	{
		nums.push_back(z);
	}
	pt = MovingPoint(nums, x, y);
	pt.calculate();
	pt.mark();
}
