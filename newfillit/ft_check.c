/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 23:09:22 by phanna            #+#    #+#             */
/*   Updated: 2017/07/03 04:46:49 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_c(char ***tetri, int nb_tetri)
{
	int i;
	int j;
	int k;
	int nb_diese;

	i = -1;
	while (++i < nb_tetri)
	{
		nb_diese = 0;
		j = -1;
		while (tetri[i][++j])
		{
			k = -1;
			while (tetri[i][j][++k])
			{
				if (tetri[i][j][k] != '#' && tetri[i][j][k] != '.')
					return (-1);
				else if (tetri[i][j][k] == '#')
					nb_diese++;
			}
			if (k != 4)
				return (-1);
		}
		if (nb_diese != 4)
			return (-1);
	}
	return (0);
}

int		ft_check_join(char **tetri)
{
	int	j;
	int	k;
	int	join;

	j = -1;
	join = 0;
	while (tetri[++j])
	{
		k = -1;
		while (tetri[j][++k])
		{
			if (tetri[j][k] == '#')
			{
				if (j != 3 && tetri[j + 1][k] == '#')
					join++;
				if (k != 3 && tetri[j][k + 1] == '#')
					join++;
				if (j != 0 && tetri[j - 1][k] == '#')
					join++;
				if (k != 0 && tetri[j][k - 1] == '#')
					join++;
			}
		}
	}
	if (join == 6 || join == 8)
		return (0);
	return (-1);
}

t_pos	*ft_check_pos(char **map, t_pos *pos)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '#')
				pos[++count] = ft_new_pos(i, j);
		}
	}
	return (pos);
}
