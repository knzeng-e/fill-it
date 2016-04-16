/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_piece3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 00:05:46 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/17 00:10:45 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_clear_lhoriz_up_left(t_map *map, int line, int col)
{
	if ((col - 1 <= 0) || (col - 2 < 0) || \
			(line + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != \
			*(map->c)) || (map->tab[line + 1][col - 1] != *(map->c)) \
			|| (map->tab[line + 1][col - 2] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 1][col - 1] = '.';
	map->tab[line + 1][col - 2] = '.';
	return (1);
}

int	ft_clear_zhoriz_right(t_map *map, int line, int col)
{
	if ((col + 1 >= map->size) || (col - 1 < 0) || \
			(line + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line][col + 1] != \
			*(map->c)) || (map->tab[line + 1][col] != *(map->c)) \
			|| (map->tab[line + 1][col - 1]) != *(map->c))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line][col + 1] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 1][col - 1] = '.';
	return (1);
}

int	ft_clear_zhoriz_left(t_map *map, int line, int col)
{
	if ((col + 1 >= map->size) || (col + 2 >= map->size) || \
			(line + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line][col + 1] != \
			*(map->c)) || (map->tab[line + 1][col + 1] != *(map->c)) \
			|| (map->tab[line + 1][col + 2]) != *(map->c))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line][col + 1] = '.';
	map->tab[line + 1][col + 1] = '.';
	map->tab[line + 1][col + 2] = '.';
	return (1);
}

int	ft_clear_zvertic_left(t_map *map, int line, int col)
{
	if ((col - 1 < 0) || (line + 1 >= map->size) || \
			(line + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col - 1] != \
			*(map->c)) || (map->tab[line + 1][col] != *(map->c)) \
			|| (map->tab[line + 2][col - 1]) != *(map->c))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line + 2][col - 1] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 1][col - 1] = '.';
	return (1);
}

int	ft_clear_zvertic_right(t_map *map, int line, int col)
{
	if ((col + 1 >= map->size) || (line + 1 >= map->size) || \
			(line + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != \
			*(map->c)) || (map->tab[line + 1][col + 1] != *(map->c)) \
			|| (map->tab[line + 2][col + 1] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line + 2][col + 1] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 1][col + 1] = '.';
	return (1);
}
