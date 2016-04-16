/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 18:20:21 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/17 00:23:13 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_insert_square(t_map *map, int line, int col)
{
	if ((line + 1 >= map->size) || (col + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != '.') || (map->tab[line + 1][col] != '.') || \
			(map->tab[line][col + 1] != '.') ||\
			(map->tab[line + 1][col + 1]) != '.')
		return (0);
	map->tab[line][col] = *(map->c);
	map->tab[line + 1][col] = *(map->c);
	map->tab[line][col + 1] = *(map->c);
	map->tab[line + 1][col + 1] = *(map->c);
	(*map->c)++;
	return (1);
}

int	ft_insert_vertic_line(t_map *map, int line, int col)
{
	int	i;

	if ((line + 1 >= map->size) || (line + 2 >= map->size) || \
			(line + 3 >= map->size))
		return (0);
	i = 0;
	while (i < 4)
	{
		if (map->tab[line + i][col] != '.')
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		map->tab[line + i][col] = *(map->c);
		i++;
	}
	(*map->c)++;
	return (1);
}

int	ft_insert_horiz_line(t_map *map, int line, int col)
{
	int	i;

	if ((col + 1 >= map->size) || (col + 2 >= map->size) || \
			(col + 3 >= map->size))
		return (0);
	i = 0;
	while (i < 4)
	{
		if (map->tab[line][col + i] != '.')
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		map->tab[line][col + i] = *(map->c);
		i++;
	}
	(*map->c)++;
	return (1);
}

int	ft_insert_lvertic_up_left(t_map *map, int line, int col)
{
	if ((col - 1 < 0) || (line + 1 >= map->size) || \
			(line + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != '.') || (map->tab[line + 1][col] != '.') || \
			(map->tab[line + 2][col] != '.') \
			|| (map->tab[line + 2][col - 1] != '.'))
		return (0);
	map->tab[line][col] = *(map->c);
	map->tab[line + 1][col] = *(map->c);
	map->tab[line + 2][col] = *(map->c);
	map->tab[line + 2][col - 1] = *(map->c);
	(*map->c)++;
	return (1);
}

int	ft_insert_lvertic_down_left(t_map *map, int line, int col)
{
	if ((col + 1 >= map->size) || (line + 1 >= map->size) || \
			(line + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != '.') || (map->tab[line][col + 1] != '.') || \
			(map->tab[line + 1][col + 1] != '.') \
			|| (map->tab[line + 2][col + 1] != '.'))
		return (0);
	map->tab[line][col] = *(map->c);
	map->tab[line][col + 1] = *(map->c);
	map->tab[line + 1][col + 1] = *(map->c);
	map->tab[line + 2][col + 1] = *(map->c);
	(*map->c)++;
	return (1);
}
