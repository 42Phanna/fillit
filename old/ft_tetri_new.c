/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:25:42 by phanna            #+#    #+#             */
/*   Updated: 2017/05/10 15:36:50 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_tetri_new(char *s)
{
	t_tetri	*new;

	if (!(new = malloc(sizeof(*new))))
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->prev = NULL;
	new->tab = ft_strdup(s);
	return (new);
}
