/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:12:20 by phanna            #+#    #+#             */
/*   Updated: 2017/07/26 14:17:53 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test_pos(t_tetri *first, char **tab, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (first->tetri[i][j] == '#' && (first->x + j >= len \
						|| first->y + i >= len))
				return (0);
			if (first->tetri[i][j] == '#' && \
					ft_isalpha(tab[first->y + i][first->x + j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

char	**place_it(t_tetri *first, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (first->tetri[i][j] == '#')
				tab[first->y + i][first->x + j] = first->letter;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

char	**delete(t_tetri *first, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == first->letter)
				tab[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

int		isplace(t_tetri *first, char **tab, int size)
{
	size = size_map(tab);
	if (first)
	{
		while (first->y * first->x < size * size)
		{
			if ((test_pos(first, tab, size)) == 1)
			{
				tab = place_it(first, tab);
				if (isplace(first->next, tab, size) == 1)
					return (1);
				tab = delete(first, tab);
			}
			if (first->x < (size - 1))
				first->x++;
			else
			{
				first->x = 0;
				first->y++;
			}
		}
		first->x = 0;
		first->y = 0;
		return (0);
	}
	return (1);
}
