/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 22:56:46 by phanna            #+#    #+#             */
/*   Updated: 2017/07/03 04:08:19 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
#include <stdio.h>

typedef	struct	s_pos
{
	int	x;
	int	y;

}				t_pos;
char	***ft_read(char *av, char ***tetri, int *i);
char	**ft_get_map_size(int nb_tetri, int len);
char	**ft_move_tetri(char **str);
int		ft_move_left(char **str);
int		ft_move_right(char **str);
int		ft_move_bot(char **str);
int		ft_move_top(char **str);
int		ft_error(char ***tetri, int nb_tetri);
int		ft_check_c(char ***tetri, int nb_tetri);
int		ft_check_join(char **tetri);
t_pos	*ft_check_pos(char **map, t_pos *pos);
t_pos	ft_new_pos(int x, int y);
t_pos	**malloc_struct(t_pos **pos, int nb_tetri);
t_pos	**create_struct(char ***tetri, t_pos **pos, int nb_tetri);

#endif
