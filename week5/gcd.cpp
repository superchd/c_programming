#include <cstdio>

class Nat
{
	int a;
public:
	Nat(int n) 
	{
		a = n;
	}
	Nat sumup(const Nat &m) 
	{
		a += m.a;
		return *this;
	}

	Nat mulup1(const Nat &n) 
	{
		a = (2 * a + n.b) * 7;
		return *this;
	}

	Nat mulup2(const Nat &n) 
	{
		a = (4 * a + n.b) * 2;
		return *this;
	}

	int ival() 
	{
		return a;
	}
};
// 이러면 Nat m의 크기가 바뀌자너
Nat add(Nat &n, Nat &m) 
{
	Nat k(n.ival()+m.ival());
	return k;
}

int gcd(int a, int b)
{
    if(b == 0){
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);

	Nat m = a, n = b;
	m.mulup1(n);
	m.


}
