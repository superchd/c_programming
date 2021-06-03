#include <iostream>
using namespace std;

const int MAX = 100;
class IntStack {
public:
	IntStack(int _size=MAX);
	IntStack(const IntStack& s) : _top(s._top), _size(s._size)
	{
		_data = new int[_size];
		for (int i = 0; i < _size; ++i)
		_data[i] = s._data[i];
	}
	const IntStack& operator = (const IntStack &s) 
	{
		if (_data) delete [] _data;
		_top = s._top;
		_size = s._size;
		_data = new int[_size];
		for (int i = 0; i < _size; ++i)
		_data[i] = s._data[i];
		return *this;
	}
	~IntStack();
	bool isfull();
	bool isempty();
	void push(int d);
	int pop();
private:
	int *_data;
	int _top, _size;
};

IntStack::IntStack(int size) : _top(0), _size(size)
{ // constructor
	_data = new int[size];
}

IntStack::~IntStack() 
{
	delete [] _data;
} // destructor

bool IntStack::isempty()
{
	return (_top == 0);
}

bool IntStack::isfull()
{
	return (_top == MAX);
}

void IntStack::push(int e) // add element in stack
{
	if(isfull())
	{
		return ;
	}
	else
	{
		_data[_top++] = e;
	}
}

int IntStack::pop() // delete and return 'top'
{
	if(isempty())
	{
		return -1;
	}

	return _data[--_top];
}

void revPrint_diff(IntStack s)
{
	int diff;
	int sum1 = 0;
	int sum2 = 0;
	int cnt = 1;
	while (!s.isempty())
	{
		if (cnt % 2 == 1)
		{
			sum1 = sum1 * 10 + s.pop();
		}
		else
		{
			sum2 = sum2 * 10 + s.pop();
		}
		cnt++;
	}
	diff = sum1 - sum2;
	if (diff < 0)
		diff *= -1;
	cout << diff << endl;
}

int main() {
	int x;
	int n;
	IntStack s;
	IntStack t;
	cin >> n;
	while (cin >> x) 
	{
	s.push(x);
	}
	t = s;
	
	revPrint_diff(s);
	return 0;
}
