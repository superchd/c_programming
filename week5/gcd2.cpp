#include <cstdio>

int gcd(int a, int b){

    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

class Nat {
	int a;
public:
	Nat(int n) 
	{
		a = n;
	}
	Nat make_n1(const Nat &m) 
	{
		a = (2 * a + m.a) * 7;
		return *this;
	}

	Nat make_n2(const Nat &m) 
	{
		a = (4 * a + m.a) * 2;
		return *this;
	}
	int ival() 
	{
		return a;
	}
};

Nat gcd(Nat &m, Nat &n) 
{
	gcd(int a, int b)
	{
		if(b == 0)
		{
			return a;
		}
		else
		{
			return gcd(b, a%b);
		}
	}

	Nat k(n.ival()+m.ival());
	return k;
}

int main()
{
	int a, b;
	int k,j;
	scanf("%d%d", &a, &b);
	Nat m = a, n = b;
	m.make_n1(b);
	n.make_n2(b);

	k = m.ival;
	j = n.ival;
	printf("%d", gcd(k, j));
}
