/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:50:29 by phanna            #+#    #+#             */
/*   Updated: 2017/05/10 15:48:25 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
#include <stdio.h>

# define BUFF_SIZE 21
typedef	struct	s_tetri
{
	char			*tab;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}				t_tetri;
int	check_char(char *s);
int	check_nb_char(char *s);
int	check_join(char *s);
int	check_nb_join(char *s);
t_tetri	*ft_tetri_new(char *s);
void	ft_tetri_add(t_tetri **lst, t_tetri *new);

#endif
