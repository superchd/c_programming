#include <iostream>

using namespace std;

class Nat 
{
	int a;
	int b;
	int G;
public:
	Nat(int n) 
	{
	a = n;
	}

	Nat operator +=(Nat &m) 
	{
	a += m.a;
	return *this;
	}

	int ival() const
	{
		return a;
	}

	void set_ival(int i)
	{
		a = i;
	}
};


	Nat operator +(const Nat &n, const Nat &m)
	{
		Nat k(n.ival() + m.ival());
		return k;
	}

	Nat operator ^(const Nat &n, const Nat &m)
	{
		if (n.ival() == 0)
			return m;
		Nat rem(m.ival() % n.ival());
		return rem ^ n;
	}

	ostream& operator << (ostream &out, const Nat &n) 
	{
	return out << n.ival() << endl;
	}

	istream& operator >> (istream& in, Nat &n)
	{
		int i = 0;
		in >> i;
		n.set_ival(i);
 		return in;
	}

int main()
{
	Nat a(0), b(0);
	cin >> a >> b;
	cout << a + b << " " << a << " " << (a ^ b) << endl;
}
