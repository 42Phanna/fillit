/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:28:47 by phanna            #+#    #+#             */
/*   Updated: 2017/07/26 13:52:35 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_tetri
{
	char			**tetri;
	char			letter;
	int				x;
	int				y;
	struct s_tetri	*next;
}					t_tetri;

int					size_map(char **map);
int					first_test(char *buf);
int					isplace(t_tetri *first, char **tab, int size);
int					get_nb_tetri(char *buff);
int					get_nb_tetri_map(char **map);
int					check(char **tab, int nb_tetri);
int					check_char(char *str);
int					check_line(char *str);
int					check_join(char *str);

static int			get_x_min(char **tab);
static int			get_y_min(char **tab);
static char			**delete(t_tetri *first, char **tab);
static char			**place_it(t_tetri *first, char **tab);
static int			test_pos(t_tetri *first, char **tab, int len);

char				**flt_read(char *argv);
char				**fill_tab(char **tab, char *buff, int nb_tetri);
char				**new_tab(int nb_tetri, int len);
char				**solve(t_tetri *start, char **tab, int nb_tetri);

static char			**move_up(int y_min, char **tab);
static char			**move_left(int x_min, char **tab);

t_tetri				*move_tetri(t_tetri *first);
t_tetri				*split_map(char **map, int nb_tetri);
t_tetri				*newtetri(char **tetri, int num);

#endif
