#include <iostream>
 using namespace std;

class Nat 
{
	int a;

	public:
	Nat(int n) 
	{
		a = n;
	}
	private:
    	int num1{ 0 }, num2{ 0 }, G{ 0 }, L{ 0 };
};

	void Test::set(int input1, int input2)
	{
    		num1 = input1;
    		num2 = input2;
	}

	void GCD();
	Nat operator +=(Nat &m) 
	{
		a += m.a;
 		return *this;
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
	Nat operator +=(Nat &m) 
	{
		a += m.a;
 		return *this;
	}
	int ival()
	{
 		return a;
	}
};

ostream& operator <<(ostream &out, Nat &n)
{
	return out << n.ival();
}

int main()
{
	Nat A;
	int a, b;
	cin >> a >> b;
	A.set(a, b);
	A.GCD();
	

}
