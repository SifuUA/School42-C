#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
/*
	unsigned short int = 65535;
	unsigned long int = 4294967295;
	unsigned long long int = 18446744073709551615;
*/
	char *str = "%f";
	double num = -2.12345678912345;

	printf("%12s\n", "MY");
	ft_printf(str, num);

	printf("%12s\n %s","MAN", "---> ");
	printf(str, num);
	printf(" <---\n");
}

