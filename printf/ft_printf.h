#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_pf
{
	struct s_pf 	*next;
	char			*str;
	char			flag;
}					t_pf;

int		ft_printf(const char * restrict format, ...);

#endif
