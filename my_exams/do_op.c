#include "do_op.h"

int		do_op(char *str1, char znak, char *str2)
{
	if (znak == '+')
		return (atoi(str1) + atoi(str2));
	else if (znak == '-')
		return (atoi(str1) - atoi(str2));
	else if (znak == '*')
		return (atoi(str1) * atoi(str2));
	else if (znak == '/')
		return (atoi(str1) / atoi(str2));
	else if (znak == '%')
		return (atoi(str1) % atoi(str2));
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc == 4)
		printf ("%d", do_op(argv[1], argv[2][0], argv[3]));
	printf("\n");
	return (0);
}
