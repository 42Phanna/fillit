/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:49:10 by phanna            #+#    #+#             */
/*   Updated: 2017/05/10 16:27:42 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	size_t		ret;
	t_tetri		*elem;
	int			file;
	static char	buf[BUFF_SIZE + 1];
	
	if (ac == 1)
		ft_putstr("missing file\n");
	file = open(av[1], O_RDONLY);
	while ((ret = read(file, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if ((check_char(buf) == 0) || (check_nb_char(buf) == 0) ||
				check_join(buf) == 0 || check_nb_join(buf) == 0)
			printf("Erreur");
		ft_tetri_add(&elem, ft_tetri_new(buf));
//		printf("%s\n", t->tab);
	}
	for (t_tetri *tmp = t ; tmp != NULL ; tmp = tmp->next)
		printf("%s\n", tmp->tab);
	t_tetri *tmp;
	for (tmp = t ; tmp->next ; tmp = tmp->next)
		;
	printf("last\n%s\n", tmp->tab);
	printf("show reverse\n");
	for ( ; tmp ; tmp = tmp->prev)
		printf("%s\n", tmp->tab);
	return (0);
}
