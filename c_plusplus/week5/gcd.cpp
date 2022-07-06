#include <cstdio>

class Nat
{
	int a;
	int b;
	int c;
	
public:
	Nat(int n) 
	{
		a = n;
	}
	Nat mulup(const Nat &q) 
	{
		a = a * q.a;
		return *this;
	}
	Nat gcd( Nat &r)
	{
	    int tmp, n;
	 
	    if(a<r.a){
		tmp = a;
		a = r.a;
		r.a = tmp;
	    }
	    while(r.a!=0){
		n = a % r.a;
		a = r.a;
		r.a = n;
	    }
	    return *this;
	}

	int ival() 
	{
		return a;
	}
};

Nat gcd(Nat &n, Nat &m)
{
	if (n.ival() == 0)
		return m;
	Nat rem = m.ival() % n.ival();
	return gcd(rem, n);
}

Nat add(Nat &n, Nat &m) {
    Nat k(n.ival() + m.ival());
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

	Nat m = a, n = b, two = 2, seven = 7;
	m.mulup(two);
	Nat p = add(m, n);
	m.mulup(two);
	Nat q = add(m, n);
	p.mulup(seven);
	q.mulup(two);
	Nat r = gcd(p, q);

	//printf("%d\n", p.ival());
	//printf("%d\n", q.ival());
	printf("%d\n", r.ival());
} 
