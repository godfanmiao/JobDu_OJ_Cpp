#include <stdio.h>
#include <math.h>

struct Record
{
	int id;
	int startHour, startMinute;
} buf[101];

int main()
{
	freopen("input.txt", "r", stdin);

	for(int i = 0; i <= 100; i++)
	{
		buf[i].startHour = -1;
		buf[i].startMinute = -1;
	}

	int id, hour, minute;
	int count = 0, sum = 0;

	char sign;

	while(scanf("%d %c %d:%d", &id, &sign, &hour, &minute) != EOF && id != -1)
	{
		if(id == 0)
		{
			if(count != 0)
			{
				float ans = sum / (count * 1.0);
				if((int)(ans * 10) % 10 >= 5)
				{
					printf("%d %d\n", count , sum / count + 1);
				}
				else
				{
					printf("%d %d\n", count , sum / count);
				}
				
			}
			else
				printf("%d %d\n", count, sum);

			for(int i = 0; i <= 100; i++)
			{
				buf[i].startHour = -1;
				buf[i].startMinute = -1;
			}
			count = 0;
			sum = 0;
		}
		else
		{			
			//printf("%d %c %d %d\n", id, sign, hour, minute);
			if(sign == 'S')
			{
				buf[id].startHour = hour;
				buf[id].startMinute = minute;
			}
			if(sign == 'E' && buf[id].startHour != -1 && buf[id].startMinute != -1)
			{
				count ++;
				sum += (hour - 1 - buf[id].startHour) * 60 + (minute + 60 - buf[id].startMinute);
				buf[id].startHour = -1;
				buf[id].startMinute = -1;
			}


		}
	}
}