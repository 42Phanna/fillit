/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 23:41:48 by phanna            #+#    #+#             */
/*   Updated: 2017/07/02 23:45:08 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_move_right(char **str)
{
	int i;
	int j;

	i = -1;
	if (str[0][3] == '.' && str[1][3] == '.' && str[2][3] == '.'
		&& str[3][3] == '.')
	{
		while (str[++i])
		{
			j = -1;
			while (str[i][++j])
			{
				if (str[i][j] == '#')
					str[i][j] = '.';
				if (str[i][j] == '#')
					str[i][j + 1] = '#';
			}
		}
		return (1);
	}
	return (0);
}

int	ft_move_left(char **str)
{
	int i;
	int j;

	i = -1;
	if (str[0][0] == '.' && str[1][0] == '.' && str[2][0] == '.'
		&& str[3][0] == '.')
	{
		while (str[++i])
		{
			j = -1;
			while (str[i][++j])
			{
				if (str[i][j] == '#')
					str[i][j] = '.';
				if (str[i][j] == '#')
					str[i][j - 1] = '#';
			}
		}
		return (1);
	}
	return (0);
}

int	ft_move_top(char **str)
{
	int	i;
	int j;

	i = -1;
	if (str[0][0] == '.' && str[0][1] == '.' && str[0][2] == '.'
		&& str[0][3] == '.')
	{
		while (str[++i])
		{
			j = -1;
			while (str[i][++j])
			{
				if (str[i][j] == '#')
					str[i][j] = '.';
				if (str[i][j] == '#')
					str[i - 1][j] = '#';
			}
		}
		return (1);
	}
	return (0);
}

int	ft_move_bot(char **str)
{
	int	i;
	int j;

	i = -1;
	if (str[3][0] == '.' && str[3][1] == '.' && str[3][2] == '.'
		&& str[3][3] == '.')
	{
		while (str[++i])
		{
			j = -1;
			while (str[i][++j])
			{
				if (str[i][j] == '#')
					str[i][j] = '.';
				if (str[i][j] == '#')
					str[i + 1][j] = '#';
			}
		}
		return (1);
	}
	return (0);
}

char	**ft_move_tetri(char **str)
{
	while (ft_move_left(str) == 1);
	while (ft_move_top(str) == 1);
	return (str);
}
