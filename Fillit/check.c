#include "inc.h"
int		mod(int x, int y, int x1, int y1)
{
	int res;
	int res1;

	res = (x - x1);
	res1 = (y - y1);
	if (res < 0)
		res = -res;
	if (res1 < 0)
		res1 = -res1;
	if (DEBUG_CHECK == 0)
	{
		printf("x = %d y = %d x1 = %d y1 = %d\n", x, y, x1, y1);
	}
	return (res + res1);
}

int		sharps_count(char*s)
{
	int i;
	int sharps;

	i = 0;
	sharps = 0;
	if (DEBUG_CHECK == 0)
	{
		printf("%s", s);
	}
	while (s[i])
	{
		if (DEBUG_CHECK == 0)
			printf("%c", *s);
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (0);
		if (s[i] == '#')
			sharps++;
			i++;
	}
	if (i >= 20)
		return (0);
	return (sharps);
}
int		check(t_figure arr,char *s)
{
	int i;
	int j;
	int x;
	int y;
	int count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		x = arr[i].x;
		y = arr[i].y;
		while (j < 4)
		{
			if (mod(x, y, arr[j].x, arr[j].y) == 1)
				count++;
			if (DEBUG_CHECK == 0)
				printf("%d\n",mod(x, arr[j].x, y, arr[j].y));
			j++;
		}
		i++;
	}
	if (sharps_count(s) != 4)
	{
		write(1, "error\n", 5);

	printf ("%d", sharps_count(s));
		return (1);
	}
	if (count >= 6)
		return (0);
	return (1);
}
