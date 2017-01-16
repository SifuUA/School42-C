#include "inc.h"

void		sort_int_tab(int *tab, unsigned int size)
{	
	int i;
	int	j;
	int tmp;

	i = 0;
	while(i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[j] > tab[j + 1] && j + 1 < size)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int			main(void)
{
	int i;
	int a[] = {19,-87,54,-65,7,6,-4,3,5,0,1,-546,846,513,-464,135,-4,68,74,-2,13,-2,46,-54,12,1,0,-0,0,0,-0,5,-34};

	i = 0;
	sort_int_tab(a, 33);
	while (i < 33)
	{
		printf("%d,", a[i]);
		i++;
	}
}
