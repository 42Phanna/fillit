/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 16:53:22 by phanna            #+#    #+#             */
/*   Updated: 2017/07/25 15:08:28 by phanna           ###   ########.fr       */
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
//	while(tab[++j])
//		ft_putendl(tab[j]);
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
//	ft_putendl("buff=");
//	ft_putendl(buff);
	nb_tetri = get_nb_tetri(buff);
//ft_putstr("nb_tetri=");
//	ft_putnbr(nb_tetri);
//	ft_putendl("");
	if (!(tmp = (char **)malloc(sizeof(char *) * (nb_tetri + 1))))
		return (NULL);
	if (first_test(buff) == 0)
		return (NULL);
	tmp = fill_tab(tmp, buff, get_nb_tetri(buff));
	return (tmp);
}

int				first_test(char *buf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (buf[x] != '\0')
	{
		if (buf[x] == '\n')
			y++;
		if (y == 4)
		{
	//		ft_putendl("#######");
	//		ft_putnbr(x);
	//		ft_putendl("");
	//		ft_putendl("#######");
			if (buf[x + 1] != '\n' && buf[x + 1] != '\0')
				return (0);
	//		ft_putendl("@@@@@@@");
			if (buf[x + 1] == '\n')
				x++;
			y = 0;
		}
		x++;
	}
	return (1);
}
