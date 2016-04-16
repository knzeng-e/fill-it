/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_piece2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 00:05:39 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/17 00:09:33 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_clear_lvertic_down_right(t_map *map, int line, int col)
{
	if ((col + 1 >= map->size) || (line + 1 >= map->size) || \
			(line + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line][col + 1] != \
			*(map->c)) || (map->tab[line + 1][col] != *(map->c)) \
			|| (map->tab[line + 2][col] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line][col + 1] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 2][col] = '.';
	return (1);
}

int	ft_clear_lvertic_up_right(t_map *map, int line, int col)
{
	if ((col + 1 >= map->size) || (line + 1 >= map->size) || \
			(line + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != \
			*(map->c)) || (map->tab[line + 2][col] != *(map->c)) \
			|| (map->tab[line + 2][col + 1] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 2][col] = '.';
	map->tab[line + 2][col + 1] = '.';
	return (1);
}

int	ft_clear_lhoriz_down_right(t_map *map, int line, int col)
{
	if ((col + 1 >= map->size) || (col + 2 >= map->size) || \
			(line + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != \
			*(map->c)) || (map->tab[line][col + 1] != *(map->c)) \
			|| (map->tab[line][col + 2] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line][col + 1] = '.';
	map->tab[line][col + 2] = '.';
	map->tab[line + 1][col] = '.';
	return (1);
}

int	ft_clear_lhoriz_down_left(t_map *map, int line, int col)
{
	if ((col + 1 >= map->size) || (col + 2 >= map->size) || \
			(line + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col + 2] != \
			*(map->c)) || (map->tab[line][col + 1] != *(map->c)) \
			|| (map->tab[line][col + 2] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line][col + 1] = '.';
	map->tab[line][col + 2] = '.';
	map->tab[line + 1][col + 2] = '.';
	return (1);
}

int	ft_clear_lhoriz_up_right(t_map *map, int line, int col)
{
	if ((col + 1 >= map->size) || (col + 2 >= map->size) || \
			(line + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line][col] != \
			*(map->c)) || (map->tab[line + 1][col] != *(map->c)) || \
			(map->tab[line + 1][col + 1] != *(map->c)) \
			|| (map->tab[line + 1][col + 2] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 1][col + 1] = '.';
	map->tab[line + 1][col + 2] = '.';
	return (1);
}
