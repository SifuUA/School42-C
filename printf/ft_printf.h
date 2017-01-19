#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_pf
{
	struct s_pf 	*next;
	char			*str;
	char			*buffer;

	char			*flag;
	char			*width;
	char			*precision;
	char			*size;
	char			specifier;
}					t_pf;

typedef void ((*ptr_f)());

int					ft_printf(const char * restrict format, ...);
char				*ft_itoa_base(unsigned long long int value, unsigned long long int base);
char				*ft_itoa_base_mod( long long int value, long long int base);
int					find(char *str, char c);
void				f_1(char cpecif, char *size, va_list vl, char **buffer);
#endif
