#include <cstdio>
/*
class Nat {
	int a;
public:
	Nat(int n) 
	{
		a = n;
	}
	Nat make_n1(const Nat &m, const Nat &n) 
	{
		a = (2 * m.a + n.b) * 7;
		return *this;
	}

	Nat make_n2(const Nat &m, const Nat &n) 
	{
		a = (4 * m.a + n.b) * 2;
		return *this;
	}
	int ival() 
	{
		return a;
	}
};

Nat add(Nat &n, Nat &m) 
{
	Nat k(n.ival()+m.ival());
	return k;
}
*/

int gcd(int a, int b){

    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	
	int n1;
	int n2;

	n1 = (2 * a + b) * 7;
	n2 = (4 * a + b) * 2;
	
	int result;

	result = gcd(n1, n2);

	printf("%d\n", result);
}
