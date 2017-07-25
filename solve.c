/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:04:04 by phanna            #+#    #+#             */
/*   Updated: 2017/07/25 13:59:37 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(t_tetri *first, char **tab, int nb_tetri)
{
	int	len;

	len = 0;
	move_tetri(first);
	tab = new_tab(nb_tetri, len);
	while (isplace(first, len, tab) == 0)
	{
		++len;
		first->x = 0;
		first->y = 0;
	}
//	tab = new_tab(nb_tetri, len);
}