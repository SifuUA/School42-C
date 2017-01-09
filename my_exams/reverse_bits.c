#include "inc.h"

int				ft_pow(int i)
{
	if (i == 0)
		return (1);
	else 
		return (2 * ft_pow(i - 1));
}
unsigned char   reverse_bits(unsigned char octet)
{
	int array[] = {0, 0, 0, 0, 0, 0, 0, 0};
	int i;
	int tmp;

	i = 7;
	tmp = 0;
	while (octet)
	{
		array[i] = octet % 2;
		octet = octet / 2;
		i--;
	}
	while (i < 8)
	{
		tmp = tmp + array[i] * ft_pow(i);	
		i++;
	}
	return((unsigned char)tmp);
}

int				main(void)
{
	unsigned char a = 65;
	printf("%d\n", reverse_bits(a));
}
