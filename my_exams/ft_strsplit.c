#include "inc.h"

static int count_of_w(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if ((*str != ' ' && *str != '\t' && *str != '\n') && (*(str + 1) == ' ' ||
		*(str + 1) == '\t' || *(str + 1) == '\n' || *(str + 1) == '\0'))
			i++;
		str++;
	}
	return (i);
}

static int	len_of_w(char **word)
{
	int j;
	int i;
	
	i = 0;
	j = 0;
	while (**word == ' ' || **word == '\t' || **word == '\n')
		(*word)++;
	while (word[i][j] != ' ' &&  word[i][j] != '\t' &&  word[i][j] != '\n' && word[i][j])
		j++;
	return (j);
}

static char    **ft_split(char *str)
{
	char	**arr;
	int 	i;
	int		j;
	char	*ptr;
	int		len_w;
	int		count_w;

	i = 0;
	ptr = str;
	count_w = count_of_w(ptr);
	arr = (char **)malloc(sizeof(char*) * count_w);
	while (i < count_w)
	{
		j = 0;
		len_w = len_of_w(&ptr);
		arr[i] = (char *)malloc(sizeof(char) * len_w + 1);
		while (j < len_w && *ptr)
		{
			arr[i][j] = *ptr;
			j++;
			ptr++;
		}
		arr[i][j] = '\0';
		i++;
	}
	return (arr);
}
int 	main(void)
{
	int i;
	char *a = "    Hi0120210 ...  a  new   life   ";
	char	**abc = ft_split(a);

	i = 0;
	while (i < 4)
	{
		printf("%s\n", abc[i]);
		i++;
	}
}
