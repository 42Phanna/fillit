/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:49:10 by phanna            #+#    #+#             */
/*   Updated: 2017/05/05 16:54:14 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_msg(void)
{
	int i = 0;
	static int j = 0;
	
	printf("adr i %p\n", &i);
	printf("adr i %p\n", &j);
	++i;
	return (i);
}

int	main(int ac, char **av)
{
	//int		i;
	char	*tab;
	int		file;
	static char	buf[BUFF_SIZE + 1];
	int		ret;
	
	while (42)
	{
		printf("value i %d\n", ft_msg());
		getchar();
	}
/*	tab = NULL;
	i = 0;
	if (ac == 1)
		ft_putstr("missing file\n");
	file = open(av[1], O_RDONLY);
	ft_memset(buf, 'A', BUFF_SIZE + 1);
	while ((ret = read(file, buf, BUFF_SIZE) != '\0'))
	{     
		buf[ret] = '\0';
		tab = ft_strjoin(tab, buf);
	}
	ft_putstr(tab);*/
	return (0);
}
