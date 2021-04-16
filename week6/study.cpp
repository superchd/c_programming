#include <iostream>
using namespace std;

class Nat {
	int a;
	public:
	Nat(int n) {
	a = n;
	}
	Nat operator +=(Nat &m) 
	{
	a += m.a;
	return *this;
	}
	int ival() {
	return a;
	}
};

	ostream& operator <<(ostream &out, Nat &n) 
	{
	return out << n.ival();
	}
	istream& operator >> (istream& in, Nat &n)
	{
		in >> n.m_x >> n.m_y >> n.m_z;

		return in;
	}
	
int main()
{
	int a, b;
	cin >> a >> b;
	Nat n(a), m(b);
	n += m;
	m += n;
	cout << n << " " << m << endl;
}
