#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char *str = "%hd\n";
	
	printf("my :\n");
	ft_printf(str, 'a');
	printf("man = ");
	printf(str, 32768);
}

