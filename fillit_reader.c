/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:53:22 by phanna            #+#    #+#             */
/*   Updated: 2017/07/26 13:08:56 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**fill_tab(char **tab, char *buff, int nb_tetri)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = -1;
	k = -1;
	while (++j < nb_tetri)
	{
		if (!(tab[j] = (char*)malloc(sizeof(char) * 21)))
			return (NULL);
		while (++k < 20)
		{
			tab[j][k] = buff[i];
			i++;
		}
		tab[j][20] = '\0';
		k = -1;
		i++;
	}
	tab[j] = NULL;
	j = -1;
	return (tab);
}

char	**flt_read(char *argv)
{
	int		fd;
	int		ret;
	int		nb_tetri;
	char	buff[4097];
	char	**tmp;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buff, 4096)))
		buff[ret] = '\0';
	nb_tetri = get_nb_tetri(buff);
	if (!(tmp = (char **)malloc(sizeof(char *) * (nb_tetri + 1))))
		return (NULL);
	if (first_test(buff) == 0)
		return (NULL);
	tmp = fill_tab(tmp, buff, get_nb_tetri(buff));
	return (tmp);
}

int		first_test(char *buf)
{
	int	t;
	int x;
	int y;

	t = 0;
	x = 0;
	y = 0;
	while (buf[x] != '\0')
	{
		if (buf[x] == '\n')
			y++;
		if (y == 4)
		{
			if ((buf[x + 1] != '\n' && buf[x + 1] != '\0') || x != (19 + t))
				return (0);
			if (buf[x + 1] == '\n')
				x++;
			t = t + 21;
			y = 0;
		}
		x++;
	}
	if (buf[x - 1] == '\n' && buf[x - 2] == '\n')
		return (0);
	return (1);
}
