#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int n = 11;
	char* alph = "abcd";
	int a = 0;
	int iter[11];
	for (int i = 0; i < n; i++)
	{
		iter[i] = 0;
	}
	int i = 0;
	int b = i + 1;
	int o = strlen(alph);
	int k = pow(o, n);
	while (a < k - 1)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c", alph[iter[j]]);
		}
		printf("\n");
		iter[i]++;
		if (iter[i] == o)
		{
			iter[b]++;
			iter[i] = 0;
			if (iter[b] == o)
			{
				while (iter[b] == o || iter[b] == o - 1)
				{
					iter[b] = 0;
					b++;
				}
				iter[b]++;
				b = i + 1;
			}
		}
		a++;
	}
	for (int j = 0; j < n; j++)
	{
		printf("%c", alph[iter[j]]);
	}
	printf("\n");
	return 0;
}
