#include <stdio.h>
#include <string.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);	
}

int		main(void)
{
	char *s1 = "";
	char *s2 = "";
	printf("my = %d\n", ft_strcmp(s1,s2));
	printf("man = %d\n", strcmp(s1,s2));
}
