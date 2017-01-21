#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *str = "%-0 #+1234.*22lld\n";
	
	printf("my :\n");
	ft_printf(str, 12);
	printf("man = ");
	printf(str, 12);
}

