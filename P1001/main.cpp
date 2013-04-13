#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);

	int m1[10][10];
	int m2[10][10];

	int m, n, tmp, count;

	while(scanf("%d", &m) != EOF && m != 0)
	{
		scanf("%d", &n);

		count = 0;

		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%d", &m1[i][j]);
			}
		}

		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%d", &tmp);
				m2[i][j] = m1[i][j] + tmp;
			}
		}

		
		bool key;
		for(int i = 0; i < m; i++)
		{
			key = true;
			for(int j = 0; j < n; j++)
			{
				if(m2[i][j] != 0)
				{
					key = false;
					break;
				}
			}
			if(key)
				count ++;
		}


		for(int i = 0; i < n; i++)
		{
			key = true;
			for(int j = 0; j < m; j++)
			{
				if(m2[j][i] != 0)
				{
					key = false;
					break;
				}
			}
			if(key)
				count ++;
		}

		printf("%d\n", count);

	}

	return 0;
}