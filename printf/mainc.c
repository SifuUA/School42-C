#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *str = "%0 #20.5ll+-d\n";
	
	printf("my :\n");
	ft_printf(str, 12);
	printf("man = ");
	printf(str, 12);
}

