#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
/*
	unsigned short int = 65535;
	unsigned long int = 4294967295;
	unsigned long long int = 18446744073709551615;
*/
	char	*str = "%.*d";
	int		num = 2;

	printf("%12s\n %s %s","MY", "--->", "<---\n");
	ft_printf(str, num, 7);

	printf("%12s\n %s","MAN", "--->");
	printf(str, num, 732);
	printf("<---\n");
}

