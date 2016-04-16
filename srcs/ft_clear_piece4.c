/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_piece4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 00:06:15 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/17 00:12:33 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_clear_t_up(t_map *map, int line, int col)
{
	if ((col - 1 < 0) || (col + 1 >= map->size) || (line + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || \
			(map->tab[line + 1][col - 1] != *(map->c)) \
			|| (map->tab[line + 1][col] != *(map->c)) \
			|| (map->tab[line + 1][col + 1] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line + 1][col - 1] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 1][col + 1] = '.';
	return (1);
}

int	ft_clear_t_right(t_map *map, int line, int col)
{
	if ((line + 2 >= map->size) || (col + 1 >= map->size) || \
			(line + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || \
			(map->tab[line + 1][col] != *(map->c)) \
			|| (map->tab[line + 1][col + 1] != *(map->c)) \
			|| (map->tab[line + 2][col] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 1][col + 1] = '.';
	map->tab[line + 2][col] = '.';
	return (1);
}

int	ft_clear_t_down(t_map *map, int line, int col)
{
	if ((line + 1 >= map->size) || (col + 1 >= map->size) || \
			(col + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || \
			(map->tab[line][col + 1] != *(map->c)) \
			|| (map->tab[line][col + 2] != *(map->c)) \
			|| (map->tab[line + 1][col + 1] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line][col + 1] = '.';
	map->tab[line][col + 2] = '.';
	map->tab[line + 1][col + 1] = '.';
	return (1);
}

int	ft_clear_t_left(t_map *map, int line, int col)
{
	if ((line + 1 >= map->size) || (col - 1 < 0) || (line + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || \
			(map->tab[line + 1][col] != *(map->c)) \
			|| (map->tab[line + 1][col - 1] != *(map->c)) \
			|| (map->tab[line + 2][col] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 1][col - 1] = '.';
	map->tab[line + 2][col] = '.';
	return (1);
}
