/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <nterrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:44:31 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/27 18:52:03 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_tab(int size)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * (size + 1));
	while (size - i)
	{
		j = 0;
		tab[i] = (char*)malloc(sizeof(char) * (size + 1));
		while (size - j)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	clear_char(char **tab, int c)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'A' + c - 1)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	print_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			write(1, tab[i] + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
