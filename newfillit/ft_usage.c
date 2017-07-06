/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 23:35:18 by phanna            #+#    #+#             */
/*   Updated: 2017/07/03 04:47:25 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(char ***tetri, int nb_tetri)
{
	int i;

	i = 0;
	if (nb_tetri == 0 || nb_tetri > 26)
		ft_putendl("nb_tetri error\n");
	if (nb_tetri == 0 || nb_tetri > 26)
		return (0);
	if (ft_check_c(tetri, nb_tetri) == -1)
		ft_putendl("invalid tetri");
	if (ft_check_c(tetri, nb_tetri) == -1)
		return (0);
	while (tetri[++i])
	{
		if (ft_check_join(tetri[i]) == -1)
			ft_putendl("tetri was not join");
		if (ft_check_join(tetri[i]) == -1)
			return (0);
	}
	return (1);
}
