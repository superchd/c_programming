#include <cstdio>

int Pascal_Number(int i, int j, int start, int end){			// This function indicates the ith floor jth number			

	if(i == j)
		return (end);
	else if (j == 1)
		return start;
	else	
		return Pascal_Number(i-1, j-1, start, end) + Pascal_Number(i-1, j, start, end);	// (m)C(n) = (m-1)C(n-1) + (m-1)C(n)

}											// Not using pactorial function can prevent overflowing

int main(void) {

	int n;
	int start, end;
	int i, j;
	scanf("%d", &n);
	if (scanf("%d %d", &start, &end) == 2)
	{

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
	else if(scanf("%d %d", &start, &end) == 1)
	{
		for(j = 1; j <= n + 1; j++)
		{
			if (Pascal_Number(n + 1, j, start ,start) < 100)
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
