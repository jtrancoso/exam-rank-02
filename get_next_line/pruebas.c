#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

char *ft_strchr(char *str, int c)
{
	int i;
	char *aux;

	i = 0;
	aux = str;
	if (!aux)
		return (NULL);
	while (aux[i] != '\0')
	{
		if (aux[i] == c)
			return (aux + i);
		i++;
	}
	return (NULL);
}

char *ft_strdup(char *str)
{
	char *aux;
	int i;

	if (!(aux = malloc(sizeof (char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *aux;
	int i;

	if (!s1 || !s2)
		return (NULL);
	aux = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		aux[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		aux[i] = *s2;
		i++;
		s2++;
	}
	aux[i] = '\0';
	return (aux);
}

int get_next_line(char **line)
{
	static char *mem;
	char buffer[256];
	char *aux;
	char *tmp1;
	char *tmp2;
	int  b_read;

	if (!line)
		return (-1);
	while (!(ft_strchr(mem, '\n')))
	{
		b_read = read(0, buffer, 255);
		if (b_read < 0)
			return (-1);
		if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		if (!mem)
			mem = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(mem, buffer);
			free (mem);
			mem = aux;
		}
	}
	if (!mem && !b_read)
	{
		*line = ft_strdup("");
		return(0);
	}
	else if ((tmp1 = ft_strchr(mem, '\n')))
	{
		*tmp1 = 0;
		*line = ft_strdup(mem);
		tmp2 = ft_strdup(++tmp1);
		free(mem);
		mem = tmp2;
	}
	else
	{
		*line = ft_strdup(mem);
		free (mem);
		mem = NULL;
		return (0);
	}
	return (1);
}
