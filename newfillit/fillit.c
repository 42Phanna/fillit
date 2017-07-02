/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 22:56:49 by phanna            #+#    #+#             */
/*   Updated: 2017/07/03 00:04:40 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	**tetri[26];
	char	**map;
	int		nb_tetri;
	int 	len;
	t_pos 	**pos;

	nb_tetri = 0;
	len = 0;
	pos = NULL;
	if (ac != 2)
		ft_putendl("missing arguments");
	if (ac != 2)
		return (0);
	ft_read(av[1], tetri, &nb_tetri);
	if (ft_error(tetri, nb_tetri) == 0)
		return (0);
	map = ft_get_map_size(nb_tetri, len);
	pos = create_struct(tetri, pos, nb_tetri);
	return (0);
}
