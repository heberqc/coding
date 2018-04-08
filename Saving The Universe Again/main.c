#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int damageCalculator(char *instructions, int dim);
int hackProgram(char *instructions, int dim);

int main()
{
	int T;
	scanf("%d", &T);
	long long D;
	char P[31];
	for (int i = 0; i < T; i++)
	{
		scanf("%lld", &D);
		scanf("%s", &P);
		int damage = damageCalculator(P, strlen(P));
		int n = 0, pos = -1;
		do
		{
			if (damage <= D)
			{
				printf("Case #%d: %d\n", (i + 1), n);
				break;
			}
			n++;
			pos = hackProgram(P, strlen(P));
			damage = damageCalculator(P, strlen(P));
			if (pos == -1)
			{
				printf("Case #%d: IMPOSSIBLE\n", (i + 1));
			}
		} while (pos > -1);
	}
	return 0;
}

int damageCalculator(char *instructions, int dim)
{
	int beamPower = 1;
	int damageSum = 0;
	for (int i = 0; i < dim; i++)
	{
		if (instructions[i] == 'C')
		{
			beamPower *= 2;
		}
		else
		{
			damageSum += beamPower;
		}
	}
	return damageSum;
}

int hackProgram(char *instructions, int dim)
{
	int pos = -1;
	for (int i = dim - 1; i > 0; i--)
	{
		if (instructions[i] == 'S' && instructions[i - 1] == 'C')
		{
			instructions[i] = 'C';
			instructions[i - 1] = 'S';
			return i;
		}
	}
	return pos;
}