#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_pf
{
	struct s_pf 	*next;
	char			*str;

	char			*flag;
	char			*width;
	char			*precision;
	char			*size;
	char			specifier;
}					t_pf;

typedef void ((*ptr_f)());

int		ft_printf(const char * restrict format, ...);

#endif
