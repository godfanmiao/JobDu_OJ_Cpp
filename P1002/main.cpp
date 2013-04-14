#include <stdio.h>

int abs(int n)
{
	return n < 0 ? -n : n;
}

float max(int x, int y, int z)
{
	int max = x;
	if(y > max)
		max = y;
	else if(z > max)
		max = z;
	return (float)max;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int P, T, G1, G2, G3, GJ;

	while(scanf("%d%d%d%d%d%d", &P, &T, &G1, &G2, &G3, &GJ) != EOF)
	{
		if(abs(G1 - G2) <= T)
		{
			printf("%.1f\n", (G1 + G2) / 2.0);
		}
		else
		{
			if(abs(G3 - G1) <= T && abs(G3 - G2) <= T)
			{
				printf("%.1f\n", max(G1, G2, G3));
			}
			else if(abs(G3 - G1) <= T)
			{
				printf("%.1f\n", (G1 + G3) / 2.0);
			}
			else if(abs(G3 - G2) <= T)
			{
				printf("%.1f\n", (G2 + G3) / 2.0);
			}
			else
			{
				printf("%.1f\n", (float)GJ);
			}
		}
	}
	
	return 0;
}