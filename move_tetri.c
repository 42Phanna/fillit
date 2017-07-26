/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:15:01 by phanna            #+#    #+#             */
/*   Updated: 2017/07/26 14:18:49 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**move_up(int y_min, char **tab)
{
	int i;

	i = 0;
	while (i + y_min < 4)
	{
		tab[i] = tab[i + y_min];
		++i;
	}
	while (i < 4 && y_min > 0)
	{
		tab[i] = "....\0";
		++i;
	}
	return (tab);
}

char	**move_left(int x_min, char **tab)
{
	int tmp;
	int i;
	int j;

	tmp = 0;
	i = -1;
	j = 0;
	while (++i < 4)
	{
		while (tab[i][j + x_min] != '\0')
		{
			tab[i][j] = tab[i][j + x_min];
			j++;
		}
		tmp = x_min;
		while (tmp > 0 && tmp > 0)
		{
			tab[i][4 - tmp] = '.';
			tmp--;
		}
		j = 0;
	}
	return (tab);
}

int		get_y_min(char **tab)
{
	int x;
	int y;
	int y_min;

	x = -1;
	y = 0;
	y_min = 0;
	while (++x < 4)
	{
		while (tab[x][y] != '#' && tab[x][y] != '\0')
			y++;
		if (y == 4)
			y_min++;
		else
			return (y_min);
		y = 0;
	}
	return (y_min);
}

int		get_x_min(char **tab)
{
	int x;
	int y;
	int x_min;

	x = -1;
	y = 0;
	x_min = 4;
	while (++x < 4)
	{
		while (tab[x][y] != '#' && tab[x][y] != '\0')
			y++;
		x_min = (y < x_min) ? y : x_min;
		y = 0;
	}
	return (x_min);
}

t_tetri	*move_tetri(t_tetri *first)
{
	t_tetri *tmp;

	tmp = first;
	while (tmp)
	{
		tmp->tetri = move_left(get_x_min(tmp->tetri), tmp->tetri);
		tmp->tetri = move_up(get_y_min(tmp->tetri), tmp->tetri);
		tmp = tmp->next;
	}
	return (first);
}
