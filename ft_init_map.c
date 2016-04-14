/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 12:05:14 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/14 12:37:06 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_init_map(t_map *map, int size_map, char c, int begin_line, int begin_column)
{
	int	i;
	int	j ;

	if (!(map->c = (char *)malloc(sizeof(char))))
		return (ERROR_MALLOC);
	*(map->c) = c;
	map->size = size_map;
	map->clear = 0;
	map->begin_line = begin_line;
	map->begin_column = begin_column;
	if (!(map->tab = (char **)malloc(sizeof(char *) * map->size)))
		return (ERROR_MALLOC);
	i = 0;
	while (i < map->size)
	{
		if (!(map->tab[i] = (char *)malloc(sizeof(char *) * map->size)))
		{
			free(map->tab);
			return (0);
		}
		j = 0;
		while (j < map->size)
			map->tab[i][j] = '.';
		i++;
	}
	return (0);
}
