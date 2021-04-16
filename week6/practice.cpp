#include <cstdio>
#include <iostream>

using namespace std;
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
	cin >> a >> b;

	int n1;
	int n2;

	int result;

	result = gcd(a, b);

	cout << result;
}
