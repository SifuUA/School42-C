#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *str = "%td\n";
	
	printf("my :\n");
	ft_printf(str, 9223372036854775808);
	printf("man = ");
	printf(str, 9223372036854775808);
}

