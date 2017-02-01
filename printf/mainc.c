#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
/*
	unsigned short int = 65535;
	unsigned long int = 4294967295;
	unsigned long long int = 18446744073709551615;
*/
	char	*str = "%.0f";

	//char	*val = "abcdef";
	//int		val = 1234567;
	float val = 2.345;
	
	printf("%12s\n","MY");
	ft_putstr(" --->");
	ft_printf(str, val);
	printf("<---\n\n");

	printf("%12s\n %s","MAN", "--->");
	printf(str, val);
	printf("<---\n");
}

