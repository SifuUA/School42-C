#include "inc.h"

static int	len(int n)
{
	int i;

	i = 0;
	while (n  > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char    	*ft_itoa(int nbr)
{
	char	*str;
	int		len_s;
	int		i;
	int		tmp;

	i = 0;
	len_s = len(nbr);
	str = (char *)malloc(sizeof(char) * len_s + 1);
	str[len_s--] = '\0';
	while (len_s >= 0)
	{
		str[len_s] = nbr % 10 + '0';
		nbr = nbr / 10;
		len_s--;
	}
	return (str);
}

int			main(void)
{
	printf("%s\n", ft_itoa(12345));
}
