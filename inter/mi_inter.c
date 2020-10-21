/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mi_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:51:06 by jtrancos          #+#    #+#             */
/*   Updated: 2020/10/20 14:04:23 by jtrancos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	char aux[255];
	int i;
	int j = 0;
	if (argc == 3)
	{
		i = 0;
		while(argv[1][i])
		{
				if (strchr(argv[2], argv[1][i]) && !(strchr(aux, argv[1][i])))
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