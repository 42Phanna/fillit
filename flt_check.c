/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flt_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:00:45 by phanna            #+#    #+#             */
/*   Updated: 2017/07/25 13:47:18 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check(char **tab, int nb_tetri)
{
	int i;

	i = -1;
	if (tab[0] == NULL)
		return (0);
	while (++i < nb_tetri)
	{
		if (check_char(tab[i]) != 1)
			return (0);
		if (check_line(tab[i]) != 1)
			return (0);
		if (check_join(tab[i]) != 1)
			return (0);
	}
	return (1);
}

int		check_char(char *str)
{
	int i;
	int ht;
	int dot;
	int endline;

	i = -1;
	ht = 0;
	dot = 0;
	endline = 0;
	while (str[++i])
	{
		if (str[i] == '#')
			++ht;
		if (str[i] == '.')
			++dot;
		if (str[i] == '\n')
			++endline;
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
	}
//	ft_putstr("ht: ");
//	ft_putnbr(ht);
//	ft_putendl("");
//	ft_putstr("dot: ");
//	ft_putnbr(dot);
//	ft_putendl("");
//	ft_putstr("endline: ");
//	ft_putnbr(endline);
//	ft_putendl("");
	if (ht != 4 || dot != 12 || endline != 4)
		return (0);
	return (1);
}

int		check_line(char *str)
{
	int i;
	int len;

	i = 0;
	while (str[i])
	{
		len = 0;
		while (str[i] != '\n' && str[i])
		{
			++len;
			++i;
		}
		if (len != 4)
			return (0);
		++i;
	}
	return (1);
}

int		check_join(char *str)
{
	int i;
	int join;

	i = -1;
	join = 0;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			if (str[i - 1] == '#')
				++join;
			if (str[i + 1] == '#')
				++join;
			if (str[i + 5] == '#')
				++join;
			if (str[i - 5] == '#')
				++join;
		}
	}
	if (join == 6 || join == 8)
		return (1);
	return (0);
}
