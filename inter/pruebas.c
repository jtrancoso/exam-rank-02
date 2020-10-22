#include <unistd.h>

char *ft_strchr(char *str, int c)
{
	char *aux;

	aux = str;
	if (!aux)
		return (NULL);
	while (*aux != c)
	{
		if (*aux == '\0')
			return (NULL);
		aux++;
	}
	return (aux);
}

int main (int argc, char **argv)
{
	char aux[255];
	int i;
	int j;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			if (ft_strchr(argv[2], argv[1][i]) && (!(ft_strchr(aux, argv[1][i]))))
			{
				write(1, &argv[1][i], 1);
				aux[j] = argv[1][i];
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}