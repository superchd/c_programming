#include <cstdio>

void	 GetNumber(int *n, int *num1, int *num2)
{
    int num = 0, ch;
    int once = 0;
    int chance = 0;

    while ((ch = getchar()) != EOF)
    {
	if(ch >= '0' && ch <= '9')
	{
		num = num * 10 + ch - '0';
		if (once == 0)
		{
			*n = num;
			once = 1;
			num = 0;
		}
	}
        else if (ch == '\n') 
		if (chance == 0)
		{
			chance = 1;
			continue;
		}
		else
			break; // 엔터키를 누르면 입력을 종료한다.
        else if (ch == ' ')
	{
		*num1 = num;
		num = 0;
		continue;
        }
    }
    if (num != 0) 
   	 *num2 = num;
}

int Pascal_Number(int i, int j, int start, int end){			// This function indicates the ith floor jth number

	if(i == j)
		return (end);
	else if (j == 1)
		return start;
	else
		return Pascal_Number(i-1, j-1, start, end) + Pascal_Number(i-1, j, start, end);	// (m)C(n) = (m-1)C(n-1) + (m-1)C(n)

}										// Not using pactorial function can prevent overflowing

int main(void) {

	int n;
	int start, end;
	int i, j;
	int num1, num2;
	num1 = 0;
	n = 0;
	GetNumber(&n, &num1, &num2);
	if (num1 != 0)
	{
		start = num1;
		end = num2;

		for(j = 1; j <= n + 2; j++)
		{
			if (Pascal_Number(n + 2, j, start ,end) < 100)
			{
				printf("%d ", Pascal_Number(n + 2, j, start ,end));
			}
			else
			{
				printf("%d ", Pascal_Number(n + 2, j, start ,end) % 100);
			}
		}
	}
	else
	{
		start = num2;
		for(j = 1; j <= n + 1; j++)
		{
			if (Pascal_Number(n + 1, j, start,start) < 100)
			{
				printf("%d ", Pascal_Number(n + 1, j, start , start));
			}
			else
			{
				printf("%d ", Pascal_Number(n + 1, j, start , start) % 100);
			}
		}
	}
	return 0;
}

