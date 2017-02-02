#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct		s_pf
{
	struct s_pf		*next;
	char			*str;
	char			*buffer;
	long long		znak;

	char			*flag;
	int				width;
	int				precision;

	char			*size;
	char			specifier;
}					t_pf;

typedef void ((*ptr_f)());

int					ft_printf(const char * restrict format, ...);

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
size_t				ft_pow(size_t nb, size_t pow);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strcat(char *restrict str1, const char *restrict str2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
char				*ft_strnew(size_t size);


char				*ft_itoa_mod(int n);
char				*ft_itoa_base(long long int value, long long int base);
char				*ft_itoa_base_low(long long int value, long long int base);
char				*ft_itoa_base_unsign( unsigned long long int value, unsigned long long int base);

int					num_len(double num);
int					find(char *str, char c);
int					find_mod(char *a, char *b, char *c, char tmp);
char				*upper_case(char **str);
void				memory_allocate(t_pf *st);

int					check_flag(char *str, char *flags);
int					find_num(char *str);
int					two_perc(t_pf *st);

int					fill_struct(t_pf *st, va_list vl);
void				fill_flags(char *str, char *flags, char **flag);
void				fill_width(char **str, int *width, va_list vl);
void				fill_precision(char **str, int *precision, va_list vl);
void				fill_size(char **str, char *sizes, char *size);

void				f_1(char cpecif, char *size, va_list vl, char **buffer);
void				f_2(char cpecif, char *size, va_list vl, char **buffer);
void				f_3(char cpecif, char *size, va_list vl, char **buffer);
void				f_4(char cpecif, char *size, va_list vl, char **buffer);
void				f_5(char cpecif, char *size, va_list vl, char **buffer);
void				f_6(char cpecif, char *size, va_list vl, char **buffer);
void				f_7(char cpecif, char *size, va_list vl, char **buffer);

void				modif_buff(t_pf *st);
char				*get_zero(t_pf *st, char a);
char				*get_space(t_pf *st);

void				mod_zer(t_pf *st, char *spaces, char *zeros, char *ptr, long long znak);
void				mod_min(t_pf *st, char *spaces, char *zeros, char *ptr, long long znak);
void				mod_plus(t_pf *st, char *spaces, char *zeros, char *ptr, long long znak);
void				mod_plus1(t_pf *st, char *spaces, char *zeros, char *ptr, long long znak);
void				mod_sp(t_pf *st, char *spaces, char *zeros, long long znak);
void				mod_sp1(t_pf *st, char *spaces, char *zeros, long long znak);
void				mod_sharp1(t_pf *st, char *tmp, int i);
void				mod_sharp(t_pf *st);
#endif
