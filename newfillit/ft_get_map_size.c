/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 23:37:37 by phanna            #+#    #+#             */
/*   Updated: 2017/07/02 23:48:24 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_get_map_size(int nb_tetri, int len)
{
	char	**map;
	int		map_size;
	int		i;

	i = -1;
	map_size = 1;
	while ((map_size * map_size) < (nb_tetri * 4))
		map_size++;
	map_size = map_size + len;
	if ((map = malloc(sizeof(char *) * (map_size + 1))) == NULL)
		return (NULL);
	map[map_size] = NULL;
	while (++i < map_size)
	{
		if ((map[i] = malloc(sizeof(char) * (map_size + 1))) == NULL)
			return (NULL);
		map[i] = ft_memset(map[i], '.', map_size);
		map[i][map_size] = '\0';
	}
	return (map);
}
