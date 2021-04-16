#include <iostream>

using namespace std;

class Nat
{
public:
    void set(int input1, int input2);
    void sum();
    void GCD();
   
private:
    int num1;
    int num2;
    int G;
};

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
		in >> n;

		return in;
	}
	

void Nat::set(int input1, int input2)
{
    num1 = input1;
    num2 = input2;
}

void Nat::sum()
{
    cout << num1 + num2 << " ";
}

void Nat::GCD()
{
    int a = num1;
    int b = num2;
    int c = 0;

    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    G = a;
    cout << G;
}

int main()
{
    Nat A;
    int a = 0, b = 0;
    cin >> a >> b;

    A.set(a, b);
    A.sum();
    A.GCD();

    return 0;
}
