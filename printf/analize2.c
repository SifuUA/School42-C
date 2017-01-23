#include "ft_printf.h"

void	f_6(char cpecif, char *size, va_list vl, char **buffer)
{
	double		tmp;
	size_t		value;
	char		*ptr;
	char		*ptr1;

	if (cpecif == 'e')
	{
/*		if (size[0] == '\0')
		{
			tmp = (long double)va_arg(vl, long double);
			value = tmp;
			*buffer = ft_itoa_mod(value);
			ptr = *buffer;
			ptr1 = ft_itoa_base((tmp * ft_pow(10, num_len(tmp))), 10);
			printf ("ptr = %s ptr1 = %s\n", ptr, ptr1);
			ptr1 += (ft_strlen(ptr) - 1);
			*buffer = ft_strcat(ptr, ptr1);
			ft_strdel(&ptr);
		}
*/	}
//	else if (cpecif == 'c' || cpecif == 's')
//		f_7(cpecif, size, vl, buffer);
}

void	f_7(char cpecif, char *size, va_list vl, char **buffer)
{
	if (cpecif == 'c')
	{
		if (size[0] == '\0' || size[0] == 'l')
			**buffer = (char)va_arg(vl, int);
	}
	else
		if (size[0] == '\0')
			*buffer = va_arg(vl, char *);
//printf("---> %s <---\n", *buffer);
}
