#include "inc.h"

void	print_bits(unsigned char octet)
{
	int	array[] = {0, 0, 0, 0, 0, 0, 0, 0};
	int i;
	int	tmp;

	i = 7;
	while (i >= 0)
	{
		array[i] = octet % 2;
		octet = octet / 2;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		tmp = array[i] + '0';
		write(1, &tmp, 1);
		i++;
	}
}

/*int		main(void)
{
	unsigned char a = 124;
	print_bits(a);
}*/
