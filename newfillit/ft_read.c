/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 22:56:54 by phanna            #+#    #+#             */
/*   Updated: 2017/07/02 23:32:31 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***ft_read(char *av, char ***tetri, int *nb_tetri)
{
	char	buffer[21 + 1];
	int		ret;
	int		fd;
	int		i;
	t_pos	**pos = NULL;

	i = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	while ((ret = read(fd, buffer, 21)))
	{
		buffer[ret] = '\0';
		tetri[i] = ft_strsplit(((const char *)buffer), '\n');
		i++;
	}
	*nb_tetri = i;
	tetri[i] = NULL;
	pos = create_struct(tetri, pos, *nb_tetri);
	return (tetri);
}
