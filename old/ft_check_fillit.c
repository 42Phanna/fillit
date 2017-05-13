/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fillit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:03:57 by phanna            #+#    #+#             */
/*   Updated: 2017/05/10 16:06:07 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_char(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if(s[i] == '.' || s[i] == '#' || s[i] == '\n')
			++i;
		else
			return(0);
	}
	return (1);
}

int	check_nb_char(char *s)
{
	int	i;
	int	h;
	int	p;
	int	n;

	i = 0;
	h = 0;
	p = 0;
	n = 0;
	while(s[i])
	{
		if(s[i] == '.')
			++p;
		if(s[i] == '#')
			++h;
		if(s[i] == '\n')
			++n;
		++i;
	}
	if(p == 12 && h == 4 && n == 5)
		return (1);
	return (0);
}

int	check_join(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if(s[i] == '#')
		{
			if(s[i + 1] == '#' || s[i + 5] == '#'
					|| s[i - 1] == '#' || s[i - 5] == '#')
				++i;
			else
				return (0);
		}
		++i;
	}
	return (1);
}

int	check_nb_join(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if(s[i] == '#')
		{
			if(s[i + 1] == '#')
				++j;
			if(s[i + 5] == '#')
				++j;
			if (s[i - 1] == '#')
				++j;
			if (s[i - 5] == '#')
				++j;
		}
		++i;
	}
	if (j == 6 || j == 8)
		return (1);
	return (0);
}
