#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
/*
	unsigned short int = 65535;
	unsigned long int = 4294967295;
	unsigned long long int = 18446744073709551615;
*/
	char	*str = "%+d";

	//char		*val = "abcdef";
	char		*val1 = "111111111";
	char		*val2 = "22222";
	int			val = -42;
	//float 	val = 2.345;
	//long int	val = -4294967296;
	printf("%12s\n","MY");
	ft_putstr(" --->");
	ft_printf(str, val);
	printf("<---\n\n");

	printf("%12s\n %s","MAN", "--->");
	printf(str, val);
	printf("<---\n");
}

