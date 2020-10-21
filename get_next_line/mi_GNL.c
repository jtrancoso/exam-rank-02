/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_GNL.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:30:38 by jtrancos          #+#    #+#             */
/*   Updated: 2020/10/21 20:33:39 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strchr(char *str, int c)
{
	char *aux;

	aux = str;
	while (*aux != c)
	{
		if (*aux == '\0')
			return (NULL);
		aux++;
	}
	return (aux);
}

char *ft_strdup(char *str)
{
	char *aux;
	int i;

	if (!(aux = malloc(sizeof(char) * (ft_strlen(str) + 1))))
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
	int i;
	char *aux;

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

int main (void)
{
	char s1[100] = "hola que";
	char s2[100] = " tal estan ustedes";
	
	printf("%s\n", ft_strjoin(s1, s2));
	printf("%s\n", ft_strdup(s2));
	printf("%d\n", ft_strlen(s1));
	printf("%s\n", ft_strchr(s1, 'l'));
}