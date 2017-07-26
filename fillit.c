/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:37:56 by phanna            #+#    #+#             */
/*   Updated: 2017/07/26 09:00:28 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**new_tab(int nb_tetri, int len)
{
	int		i;
	int		size;
	char	**tab;

	i = -1;
	size = 1;
	while ((size * size) < (nb_tetri * 4))
		size++;
	size = size + len;
	if (!(tab = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	tab[size] = NULL;
	while (++i < size)
	{
		if (!(tab[i] = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		tab[i] = ft_memset(tab[i], '.', size);
		tab[i][size] = '\0';
	}
	return (tab);
}

int		main(int ac, char **av)
{
	int		nb_tetri;
	char	**tab;
	char	**map;
	t_tetri	*first;

	tab = NULL;
	if (ac != 2)
	{
		ft_putendl("too many arguments");
		return (-1);
	}
	if (!(map = flt_read(av[1])))
	{
		ft_putendl("error");
		return (-1);
	}
	nb_tetri = get_nb_tetri_map(map);
	if (check(map, nb_tetri) == 0)
	{
		ft_putendl("error");
		return (-1);
	}
	first = split_map(map, nb_tetri);
	solve(first, tab, nb_tetri);
	return (1);
}
