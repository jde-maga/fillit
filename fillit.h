/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:13:39 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/27 19:03:03 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_pixel
{
	int				x;
	int				y;
}					t_pixel;

typedef struct		s_piece
{
	t_pixel			pixel[4];
	struct s_piece	*next;
}					t_piece;

char				**create_tab(int size);
void				clear_char(char **tab, int c);
void				print_tab(char **tab);

t_piece				*new_piece(t_piece **first);
void				move_pixels(t_piece **first);

t_piece				*add_pixel(int nb_pixel, int i, t_piece **first);
int					check_contacts(t_piece *piece);
int					check_piece(char *piece, t_piece **firs);
int					check_file(char *file, t_piece **first);

void				fillit(t_piece **first);
int					solve(char **tab, t_piece *piece, int c);
int					is_putable(char **tab, t_piece *piece, int i, int j);
void				put_piece(char **tab, t_piece *piece, int c, int ij);
#endif
