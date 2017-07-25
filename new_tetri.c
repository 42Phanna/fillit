/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 18:18:08 by phanna            #+#    #+#             */
/*   Updated: 2017/07/20 12:11:22 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*newtetri(char **tetri, int num)
{
	t_tetri *box;

	box = NULL;
	box = (t_tetri*)malloc(sizeof(t_tetri));
	if (box == NULL)
		return (NULL);
	box->tetri = tetri;
	box->letter = 'A' + num;
	box->x = 0;
	box->y = 0;
	box->next = NULL;
	return (box);
}

t_tetri	*split_map(char **map, int nb_tetri)
{
	int		i;
	t_tetri *first;
	t_tetri *ptr;

	i = 0;
	first = NULL;
	ptr = NULL;
	first = newtetri(ft_strsplit(map[0], '\n'), 0);
	ptr = first;
	while (++i < nb_tetri)
	{
		ptr->next = newtetri(ft_strsplit(map[i], '\n'), i);
		ptr = ptr->next;
	}
	ptr->next = NULL;
	return (first);
}
