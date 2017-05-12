/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:09:08 by phanna            #+#    #+#             */
/*   Updated: 2017/05/12 16:37:18 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pos	ft_new_pos(int x, int y)
{
	t_pos	pos;

	//if(!(pos = malloc(sizeof(pos))))
	//	return(0);
	pos.x = x;
	pos.y = y;
	return(pos);
}

t_pos	*ft_check_pos(char **map, t_pos *pos)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = -1;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == '#')
			{
				pos[++count] = ft_new_pos(j, i);
				printf("x:%d ---> ", j);
				printf("y:%d\n", i);
			}
			++j;
		}
		++i;
	}
	return (pos);
}
