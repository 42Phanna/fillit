/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:04:04 by phanna            #+#    #+#             */
/*   Updated: 2017/07/26 14:16:09 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**solve(t_tetri *first, char **tab, int nb_tetri)
{
	int	i;
	int	len;
	int	size;

	i = -1;
	len = 0;
	size = 0;
	move_tetri(first);
	tab = new_tab(nb_tetri, len);
	while (isplace(first, tab, size) == 0)
	{
		++len;
		first->x = 0;
		first->y = 0;
		tab = new_tab(nb_tetri, len);
	}
	while (tab[++i])
		ft_putendl(tab[i]);
	return (tab);
}

int		size_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		++i;
	return (i);
}
