#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cctype>

using namespace std;

int g_check = 0;

class IntSet {
public:
	IntSet(int *ns, int size) : _ns(ns), _size(size)
	{}

	void map(int n, char op);
	void print(ostream &out);

private:
	int *_ns;
	int _size;
};


void IntSet::map(int n, char op)
{
	int size;

	size = _size;

	for(int i = 0; i < size ; i++ )
	{
		if ( op == '+' )
		{
			if ( isalpha(n) == 1 || isalpha(n) == 2 )
			{
				cout << "error in +" << endl;
				g_check = 1;
				return ;
			}
			_ns[i] = _ns[i] + n;
		}
		else if ( op == '-' )
		{
			if ( isalpha(n) == 1 || isalpha(n) == 2 )
			{
				cout << "error in -" << endl;
				g_check = 1;
				return ;
			}			
			_ns[i] = _ns[i] - n;
		}
		else if ( op == '*' )
		{
			if ( isalpha(n) == 1 || isalpha(n) == 2 )
			{
				cout << "error in *" << endl;
				g_check = 1;
				return ;
			}
			_ns[i] = _ns[i] * n;
		}
		else if ( op == '/' )
		{
			if (isalpha(n) == 1 || isalpha(n) == 2)
			{
				cout << "error in /" << endl;
				g_check = 1;
				return ;
			}
			_ns[i] = _ns[i] / n;
		}
		else if ( op == '%')
		{
			if (isalpha(n) == 1 || isalpha(n) == 2)
			{
				cout << "error in %" << endl;
				g_check = 1;
				return ;
			}
			_ns[i] = _ns[i] % n;
		}
		else
		{
			g_check = 1;
			return;
		}
	}
}

void IntSet::print(ostream &out)
{
	int size;

	size = _size;

	for(int i = 0; i < size ; i++)
	{
		if (i != size - 1)
		{
   			out << _ns[i] << ' ';
		}
		else
		{
			out << _ns[i];
		}
	}

}

void error_print(char k)
{
	if (k == '+')
		cout << "error in +" << endl;
	else if(k == '-')
		cout << "error in -" << endl;
	else if(k == '/')
		cout << "error in /" << endl;
	else if(k == '%')
		cout << "error in %" << endl;
	else if(k == '*')
		cout << "error in *" << endl;
	else
		return;
}
int main() {
	
	int x;
	float n;
	char check;
	char op;
	int k = 0;
	vector<int> array; 
	
	try
	{
		cin >> n;
		cin >> op;
		if (!(n >= 1 && n <= 9))
			throw n;

	while (cin >> x)
	{
		array.push_back(x);
		k++;
	}
	int *arr = new int(k);
	for (int i = 0; i < k ; i++)
	{
		arr[i] = array[i];
	}
	IntSet s(arr, k);
	s.map(n, op);
	if (g_check == 0)
	{
		s.print(cout);
	}
	}
	catch (int exception)
	{
		

	}
}
/*
 int main()
 try 
{
 	int x = 0, y = 0;
 	cin >> x >> y;
 	if (y == 0) throw y;
 	cout << x << " / " << y << " = " << x / y << endl;
}
 catch (int n) 
{
	cout << "error on operand " << n << endl;
}
*/
