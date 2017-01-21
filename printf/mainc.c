#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *str = "%\n";
	
	printf("my :\n");
	ft_printf(str, 10, 30, 4);
	printf("man = ");
	printf(str, 10, 30, 4);
}

