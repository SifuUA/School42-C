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
	//ft_printf("abcd%nabcd%njhjjk%n", &val, &val1, &val2);
	a = ft_printf("%c%c%c%c%c", '\0', 'a','\0','b','\0');
	printf("<---\n\n");
	ft_printf("my = %d\n",a);


	printf("%12s\n %s","MAN", "--->");
	b = printf("%c%c%c%c%c", '\0', 'a','\0','b','\0');
	printf("<---\n");
	ft_printf("man = %d\n",b);
}

