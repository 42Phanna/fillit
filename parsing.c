/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:49:10 by phanna            #+#    #+#             */
/*   Updated: 2017/05/05 16:54:14 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		i = 0;
	int		j = 0;
	size_t		ret;
	int		file;
	char		*tab;
	char		**mal;
	static char	buf[BUFF_SIZE + 1];
	
	tab = NULL;
	if (ac == 1)
		ft_putstr("missing file\n");
	file = open(av[1], O_RDONLY);
	while ((ret = read(file, buf, BUFF_SIZE)))
	{
	//	printf("OK\n");
		buf[ret] = '\0';
	//	printf("OK2\n");
		/*tab = ft_strjoin(tab, buf);
		printf("OK3\n");*/
		tab = buf;
	}
	while (tab[i] != '\0')
	{
		if(tab[i] == '\n' && tab[++i] == '\n')
			tab[i++] = 'x';
		++i;
	}
	mal = ft_strsplit(tab, 'x');
	while(mal[j])
	{
		ft_putnbr(j);
		ft_putchar('\n');
		ft_putstr(mal[j]);
		ft_putchar('\n');
		j++;
	}
	j = 0;
	while(mal[j])
	{
		int	k;
		int	nb_h;
		int	nb_p;
		int	nb_n;

		nb_h = 0;
		nb_p = 0;
		nb_n= 0;
		k = 0;
		while (mal[j][k])
		{
			if (mal[j][k] == '#')
				++nb_h;
			else if (mal[j][k] =='.')
				++nb_p;
			else if (mal[j][k] == '\n')
				++nb_n;
			else
				printf("Not good char");
			k++;
		}
		if (nb_h == 4 && nb_p == 12 && nb_n == 4)
			printf("OK\n");
		else
			printf("Not good");
		j++;
	}
	return (0);
}
