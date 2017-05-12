/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:39:32 by jcoutare          #+#    #+#             */
/*   Updated: 2017/05/12 16:00:14 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***ft_read(char *av, char ***tetri, int *nb_tetri)
{
	char	buffer[21 + 1];
	t_pos	**pos;
	int		ret;
	int		fd;
	int		i;

	if(!(pos = malloc(sizeof(*pos))))
		return (0);
	i = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	while ((ret = read(fd, buffer, 21)))
	{
		buffer[ret] = '\0';
		tetri[i] = ft_strsplit(((const char *)buffer), '\n');
		pos[i] = ft_check_pos(tetri[i]);
		printf("%d\n", pos[i]->x);
		printf("%d\n", pos[i]->y);
		i++;
	}
	//printf("nb i: %d\n", i);
	*nb_tetri = i;
	tetri[i] = NULL;
	return (tetri);
}

int		ft_check_c(char ***tetri, int nb_tetri)
{
	int nb_diese;
	int i;
	int j;
	int k;

	i = 0;
	while (i < nb_tetri)
	{
		nb_diese = 0;
		j = 0;
		while (tetri[i][j])
		{
			k = 0;
			while (tetri[i][j][k])
			{
				if (tetri[i][j][k] != '#' && tetri[i][j][k] != '.')
					return (-1);
				else if (tetri[i][j][k] == '#')
					nb_diese++;
				k++;
			}
			if (k != 4)
				return (-1);
			j++;
		}
		if (nb_diese != 4)
			return (-1);
		i++;
	}
	return (0);
}

int		ft_check_join(char **tetri)
{
	int	join;
	int	j;
	int	k;

	join = 0;
	j = 0;
	while (tetri[j])
	{
		k = 0;
		while (tetri[j][k])
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
			k++;
		}
		j++;
	}
//	printf("> join = %d\n", join);
	if (join == 6 || join == 8)
		return (0);
	return (-1);
}
