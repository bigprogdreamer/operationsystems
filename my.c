#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

void iter_alph(char* alph, int iter[], int n)
{
	volatile int i = 0;
	int b = i + 1;
	int o = strlen(alph);
	while (1)
	{
		//for (int j = 0; j < n; j++)
		//{
		//printf("%c", alph[iter[j]]);
		//}
		//printf("\n");
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
					if (b == n)
						return;
				}
				iter[b]++;
				b = i + 1;
			}
		}
	}
}
void brute_recu(char* password, char* alph, int pos)
{
	int i = 0;
	if (pos < 0)
		return;
	for (i = 0; alph[i]; ++i)
	{
		password[pos] = alph[i];
		brute_recu(password, alph, pos - 1);
	}
}
int main()
{
	const int n = 6;
	char* alph = "qwertyuioasdfghjklzxcvbn12345678";
	int iter[n];
	iter[n - 1] = 0;
	char password[n + 1];
	password[n] = 0;
	// brute_recu(password, alph, n - 1);

	for (int i = 0; i < n; i++)
	{
		iter[i] = 0;
	}

	iter_alph(alph, iter, n);
	return 0;
}

// alphabet 2 sequence length 30: iter: 2.3, recu: 3.7
// alphabet 32 sequence length 6: iter: 2.7, recu: 2.9