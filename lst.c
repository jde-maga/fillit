/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nterrier <nterrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:26:15 by nterrier          #+#    #+#             */
/*   Updated: 2016/01/27 17:43:55 by nterrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*new_piece(t_piece **first)
{
	t_piece *new;
	t_piece *current;

	new = (t_piece*)malloc(sizeof(t_piece));
	new->next = NULL;
	if (first == NULL)
		return (new);
	else
	{
		current = *first;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (new);
}

void	move_pixels(t_piece **first)
{
	t_piece	*current;
	int		i;

	current = *first;
	while (current)
	{
		i = 4;
		while (i)
			current->pixel[--i].x -= current->pixel[0].x;
		i = 4;
		while (i)
			current->pixel[--i].y -= current->pixel[0].y;
		current = current->next;
	}
}
