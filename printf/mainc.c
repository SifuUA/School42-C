#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>


int		main(void)
{
	setlocale(LC_ALL, "");
/*
	unsigned short int = 65535;
	unsigned long int = 4294967295;
	unsigned long long int = 18446744073709551615;
*/
	char	*str = "@main_ftprintf: %####0000 33..1..#00d";
	
	int			val;
	int			val1;
	int			val2;
	int			a;
	int			b;

	//char		*val = "4294967295";
	//char		*val = "abcdef";
	//char		*val1 = "111111111";
	//char		*val2 = "22222";
	//intmax_t	val =  -4294967296;
	//float 	val = 2.345;
	//long int	val = -4294967296;
	printf("%12s\n","MY");
	ft_putstr(" --->");
	ft_printf("%-40.20f", 4.26);
	//ft_printf("val %d, val1 %d, val2 %d", val, val1, val2);
	//a = ft_printf("%lS", L"Á±≥");
	printf("<---\n\n");
	ft_printf("my = %d\n",a);


	printf("%12s\n %s","MAN", "--->");
	//b = printf("%n", );
	printf("%-40.20f", 4.26);
	//printf("val %d, val1 %d, val2 %d", val, val1, val2);
	printf("<---\n");
	ft_printf("man = %d\n",b);
}

