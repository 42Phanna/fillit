/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:55:53 by phanna            #+#    #+#             */
/*   Updated: 2017/07/26 09:09:13 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	get_nb_tetri(char *buff)
{
	int i;
	int nb_tetri;

	i = -1;
	nb_tetri = 0;
	while (buff[++i])
	{
		if (buff[i] == '\n' && (buff[i + 1] == '\n' || buff[i + 1] == '\0'))
			nb_tetri++;
	}
	return (nb_tetri);
}

int	get_nb_tetri_map(char **map)
{
	int	i;
	int	nb_tetri;

	i = -1;
	nb_tetri = 0;
	while (map[++i])
		nb_tetri = nb_tetri + get_nb_tetri(map[i]);
	return (nb_tetri);
}
