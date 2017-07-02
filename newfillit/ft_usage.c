/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 23:35:18 by phanna            #+#    #+#             */
/*   Updated: 2017/07/02 23:35:40 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(char ***tetri, int nb_tetri)
{
	int i;

	i = -1;
	if (nb_tetri == 0 || nb_tetri > 26)
		ft_putendl("Nb_tetri error\n");
	if (nb_tetri == 0 || nb_tetri > 26)
		return (0);
	if (ft_check_c(tetri, nb_tetri) == -1)
		ft_putendl("invalid tetri");
	if (ft_check_c(tetri, nb_tetri) == -1)
		return (0);
	while (tetri[++i])
	{
		if (ft_check_join(tetri[i]) == -1)
			ft_putendl("tetri not connected");
		if (ft_check_join(tetri[i]) == -1)
			return (0);
		tetri[i] = ft_move_tetri(tetri[i]);
	}
	return (1);
}
