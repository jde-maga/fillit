/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:10:40 by nterrier          #+#    #+#             */
/*   Updated: 2016/02/05 20:11:51 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_piece(char **tab, t_piece *piece, int c, int ij)
{
	int i;
	int j;

	i = ij / 100;
	j = ij % 100;
	tab[j + piece->pixel[0].y][i + piece->pixel[0].x] = 'A' + c - 1;
	tab[j + piece->pixel[1].y][i + piece->pixel[1].x] = 'A' + c - 1;
	tab[j + piece->pixel[2].y][i + piece->pixel[2].x] = 'A' + c - 1;
	tab[j + piece->pixel[3].y][i + piece->pixel[3].x] = 'A' + c - 1;
}

int		is_putable(char **tab, t_piece *piece, int i, int j)
{
	int pix;
	int in_zone;
	int size;

	size = 0;
	while (tab[size] != NULL)
		size++;
	in_zone = 0;
	pix = 0;
	while (4 - pix)
	{
		if (piece->pixel[pix].y >= -j && (j + piece->pixel[pix].y) < size &&
			piece->pixel[pix].x >= -i && (i + piece->pixel[pix].x) < size)
		{
			if (tab[j + piece->pixel[pix].y][i + piece->pixel[pix].x] == '.')
			{
				in_zone++;
			}
		}
		pix++;
	}
	return (in_zone == 4);
}

int		solve(char **tab, t_piece *piece, int c)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == '.')
			{
				if (is_putable(tab, piece, i, j))
				{
					put_piece(tab, piece, c, i * 100 + j);
					if (piece->next == NULL || solve(tab, piece->next, c + 1))
						return (1);
					clear_char(tab, c);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

void	fillit(t_piece **first)
{
	int		size;
	int		filled;
	char	**tab;
	int		i;

	i = 0;
	filled = 0;
	size = 2;
	move_pixels(first);
	while (filled == 0)
	{
		tab = create_tab(size);
		filled = solve(tab, *first, 1);
		size++;
		if (filled)
			print_tab(tab);
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

int		main(int argc, char **argv)
{
	int		ret;
	int		fd;
	char	*buff;
	t_piece	*piece;
	t_piece **first;

	buff = (char*)malloc(sizeof(char) * 551);
	piece = new_piece(NULL);
	first = &piece;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			read(fd, buff, 550);
			ret = check_file(buff, first);
			close(fd);
		}
	}
	free(buff);
	if (argc != 2 || fd < 0 || ret == 0)
		return (write(1, "error\n", 6) || 1);
	fillit(first);
	return (0);
}
