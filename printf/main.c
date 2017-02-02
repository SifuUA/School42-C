#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{

	char	*s;
	int		v;

	s = "%#08x";
	v = 12345;
	
	printf("%12s\n", "MY");
	ft_putstr("--->");
	ft_printf(s, v);
	ft_putstr("<---");
	printf("\n*************************************\n");
	printf("%12s\n","MAN" );
	printf("--->");
	printf(s, v);
	printf("<---");
}
