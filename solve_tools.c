/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:12:20 by phanna            #+#    #+#             */
/*   Updated: 2017/07/25 15:07:29 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		test_pos(t_tetri *first, char **tab, int len)
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

static char		**place_it(t_tetri *first, char **tab)
{
	int i;
	int j;
	int	t = -1;

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
	//	while(tab[++t])
	//		ft_putendl(tab[t]);
		j = 0;
		i++;
	}
	return (tab);
}

static char		**delete(t_tetri *first, char **tab)
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

int				isplace(t_tetri *first, int len, char **tab)
{
	int	i;
	int	j = -1;

	i = -1;
//	ft_putendl("OK1");
	if (first)
	{
		while (first->y * first->x < len * len)
		{
	//		ft_putendl("OK2");
			if ((test_pos(first, tab, len)) == 1)
			{
				tab = place_it(first, tab);
		//		while (tab[++j])
//ft_putendl(tab[j]);
				if (isplace(first->next, len, tab) == 1)
					return (1);
		//		ft_putendl("OK3");
				tab = delete(first, tab);
			}
			if (first->x < len)
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
	i = -1;
	while (tab[++i])
		ft_putendl(tab[i]);
	return (1);
}
