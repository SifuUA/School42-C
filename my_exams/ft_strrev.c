#include <stdio.h>
#include <unistd.h>

char	*ft_strrev(char *str)
{
	char 	*ptr;
	char 	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (--i > 0)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		j++;
		i--;
	}
	return (str);
}

int		main(void)
{
	char a[] = "abcd";
	printf ("%s\n", ft_strrev(a));
}
