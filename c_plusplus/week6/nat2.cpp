#include <iostream>

using namespace std;

class Test
{
public:
    void set(int input1, int input2);
    void GCD();
    void LCM();
private:
    int num1{ 0 }, num2{ 0 }, G{ 0 }, L{ 0 };
};

void Test::set(int input1, int input2)
{
    num1 = input1;
    num2 = input2;
}

void Test::GCD()
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
    printf("최대 공약수는 %d입니다.\n", G);
}

void Test::LCM()
{
    if (G != 0)
    {
        L = num1 * num2 / G;
        printf("최소 공배수는 %d입니다.\n", L);
    }
}

int main()
{
    Test A;
    int a = 0, b = 0;

    cout << "두 수를 입력하시오 : ";
    cin >> a >> b;

    A.set(a, b);
    A.GCD();
    A.LCM();

    return 0;
}
