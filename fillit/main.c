/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:43:09 by jcoutare          #+#    #+#             */
/*   Updated: 2017/05/12 16:22:01 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_map_size(int nb_tetri)
{
	char	**map;
	int		map_size;
	int		i;

	i = 0;
	map_size = 1;
	while ((map_size * map_size) < (nb_tetri * 4))
		map_size++;
	if ((map = malloc(sizeof(char *) * (map_size + 1))) == NULL)
		return (NULL);
	map[map_size] = NULL;
	while (i < map_size)
	{
		if ((map[i] = malloc(sizeof(char) * (map_size + 1))) == NULL)
			return (NULL);
		map[i] = ft_memset(map[i], '.', map_size);
		map[i][map_size] = '\0';
		i++;
	}
	return (map);
}

int		main(int ac, char **av)
{
	char	**tetri[26];
	char	**map;
	int		nb_tetri;
	int		i;

	i = 0;
	nb_tetri = 0;
	if (ac != 2)
	{
		printf("Les arguments trou du cul\n");
		return (0);
	}
	ft_read(av[1], tetri, &nb_tetri);
/*	printf("> nb_tetri = %d\n", nb_tetri);
	printf("> ft_check_c = %d\n", ft_check_c(tetri, nb_tetri));
	while (tetri[i])
	{
		printf("> ft_check_join = %d\n", ft_check_join(tetri[i]));
		ft_print_words_tables(tetri[i]);
		printf("----\n");
		i++;
	}
	printf("Map >\n");*/
	map = get_map_size(nb_tetri);
//	ft_print_words_tables(map);
//	printf("~~~~\n");
	return (0);
}
