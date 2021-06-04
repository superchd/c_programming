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
	int p, q;
	vector<int> nums;
public:
    MovingPoint(int x = 0, int y = 0): Point(x, y) {}
    MovingPoint(vector<int> a) : nums(a) {}
    void mark(int x, int y);
    void calculate();
    int get_p() {return p;}
    int get_q() {return q;}
};

ostream& operator <<(ostream& out, MovingPoint p) 
{
    return out << "(" << p.x() << ", " << p.y() << ")";
}
// Board라는 클래스가 왜 필요한지를 모르겠다 ............

void MovingPoint::mark(int a, int b)
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
		if (i == b - 1)
			buf << "| " << setw(a) << "." << setw(x() - a) << " |" << endl;
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
	p = 0;
	q = 0;
	for (int i = 0; i < nums.size() ; i++)
	{
		if (nums[i] % 2 == 0)
			p++;
		else
			q++;
	}
}

int main() 
{
	int x;
	int y;
	vector<int> nums;

	cin >> x >> y;
	MovingPoint pt(x, y);
	while (cin >> x)
	{
		nums.push_back(x);
	}
	pt = MovingPoint(nums);
	pt.calculate();
	pt.mark(pt.get_p(), pt.get_q());
}
