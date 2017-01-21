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
	int				width;
	int				precision;

	char			*size;
	char			specifier;
}					t_pf;

typedef void ((*ptr_f)());

int					ft_printf(const char * restrict format, ...);

char				*ft_itoa_base(unsigned long long int value,
	   				unsigned long long int base);
char				*ft_itoa_base_m( long long int value, long long int base);

int					find(char *str, char c);
void    			memory_allocate(t_pf *st);
void    			fill_struct(t_pf *st, va_list vl);
void    			fill_flags(char *str, char *flags, char *flag);
void    			fill_width(char **str, int *width, va_list vl);
void    			fill_precision(char **str, int *precision, va_list vl);
void    			fill_size(char **str, char *sizes, char *size);
void				f_1(char cpecif, char *size, va_list vl, char **buffer);

#endif
