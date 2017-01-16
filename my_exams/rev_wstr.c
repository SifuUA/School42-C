#include "inc.h"

static void		put_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

static int		len_of_w(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (**str == ' ')
		(*str)++;
	while (str[i][j] != ' ' && str[i][j])
		j++;
	return (j);
	
}

static int		count_of_w(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static void		rev_print(char **arr, int count_w)
{
	while (count_w > 0)
	{
		put_str(arr[count_w - 1]);
		count_w--;
		if (count_w > 0)
			write(1, " ", 1);
		
	}
}

static void		rev(char *str)
{
	char 	**arr;
	char	*ptr;
	int		i;
	int		j;
	int		count_w;
	int		len_w;

	i = 0;
	ptr = str;
	count_w = count_of_w(ptr);
	arr = (char **)malloc(sizeof(char*) * count_w);
	while (i < count_w)
	{
		j = 0;
		len_w = len_of_w(&ptr);
		arr[i] = (char *)malloc(sizeof(char) * len_w + 1);
		while (j < len_w)
		{
			arr[i][j] = *ptr;
			j++;
			ptr++;
		}
		arr[i][j] = '\0';
		i++;
	}
	rev_print(arr, count_w);
}


int				main(int argc, char **argv)
{
	if (argc == 2)
		rev(argv[1]);
	write(1, "\n", 1);
}

