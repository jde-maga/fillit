/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:40:15 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/26 18:19:07 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*add_pixel(int nb_pixel, int i, t_piece **first)
{
	t_piece *piece;

	piece = *first;
	while (piece->next)
		piece = piece->next;
	if (nb_pixel < 4 && nb_pixel > -1)
	{
		piece->pixel[nb_pixel].x = i % 5;
		piece->pixel[nb_pixel].y = (i + 4) / 5;
	}
	return (piece);
}

int		check_contacts(t_piece *piece)
{
	int contacts;
	int a;
	int b;
	int difx;
	int dify;

	contacts = 0;
	a = 0;
	b = 0;
	while (3 - a)
	{
		b = a + 1;
		while (4 - b)
		{
			difx = piece->pixel[a].x - piece->pixel[b].x;
			dify = piece->pixel[a].y - piece->pixel[b].y;
			if (difx * difx + dify * dify == 1)
				contacts++;
			b++;
		}
		a++;
	}
	return (contacts >= 3);
}

int		check_piece(char *piece, t_piece **first)
{
	int		nb_dieses;
	int		i;

	i = 1;
	nb_dieses = 0;
	while (i % 21)
	{
		while (i % 5)
		{
			if (piece[i - 1] == '#')
			{
				add_pixel(nb_dieses, i, first);
				nb_dieses++;
			}
			if (piece[i - 1] == '.' || piece[i - 1] == '#')
				i++;
			else
				return (0);
		}
		if (piece[i - 1] == '\n')
			i++;
		else
			return (0);
	}
	return (nb_dieses == 4);
}

int		check_file(char *file, t_piece **first)
{
	int		nb_pieces;
	int		ret;
	t_piece *piece;

	piece = *first;
	nb_pieces = 1;
	ret = 1;
	while (nb_pieces > 0 && nb_pieces < 27 && ret)
	{
		ret = check_piece(&file[nb_pieces * 21 - 21], first);
		ret *= check_contacts(add_pixel(-1, -1, first));
		if (file[nb_pieces * 21 - 1] == '\n')
		{
			nb_pieces++;
			new_piece(first);
		}
		else
			nb_pieces = -nb_pieces;
	}
	if (nb_pieces > 26 || file[nb_pieces * -21 - 1] != '\0' || ret == 0)
		return (0);
	return (1);
}
