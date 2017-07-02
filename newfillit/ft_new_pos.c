/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_pose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 22:56:55 by phanna            #+#    #+#             */
/*   Updated: 2017/07/02 23:32:31 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pos	ft_new_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return(pos);
}

t_pos	**malloc_struct(t_pos **pos, int nb_tetri)
{
	int i;

	i = -1;
	if (!(pos = malloc(sizeof(pos) * nb_tetri)))
		return (NULL);
	while (++i < nb_tetri)
	{
		if (!(pos[i] = malloc(sizeof(*pos) * 4)))
			return (NULL);
	}
	return (pos);
}

t_pos	**create_struct(char ***tetri, t_pos **pos, int nb_tetri)
{
	int i;

	i = -1;
	pos = malloc_struct(pos, nb_tetri);
	while (tetri[++i])
		pos[i] = ft_check_pos(tetri[i], pos[i]);
	return (pos);
}
