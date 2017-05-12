/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:40:08 by jcoutare          #+#    #+#             */
/*   Updated: 2017/05/12 16:37:21 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef	struct	s_pos
{
	int	x;
	int	y;

}				t_pos;
char	***ft_read(char *av, char ***tetri, int *i);
t_pos	*ft_check_pos(char **map, t_pos *pos);
int		ft_check_c(char ***tetri, int nb_tetri);
int		ft_diese(char ***tetri, int nb_tetri);
int		ft_check_join(char **tetri);
t_pos	ft_new_pos(int x, int y);
#endif
