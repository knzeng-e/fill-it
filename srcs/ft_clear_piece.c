/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 18:20:21 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/16 01:29:48 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_clear_square(t_map *map, int line, int col)
{
	if ((line + 1 >= map->size) || (col + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != *(map->c)) || (map->tab[line][col + 1] != *(map->c)) ||\
			(map->tab[line + 1][col + 1]) != *(map->c))
		return (0);
	map->tab[line][col] =  '.';
	map->tab[line + 1][col] = '.';
	map->tab[line][col + 1] = '.';
	map->tab[line + 1][col + 1] = '.';
	return (1);
}

int	ft_clear_vertic_line(t_map *map, int line, int col)
{
	int	i;

	if ((line + 1 >= map->size) || (line + 2 >= map->size) || \
			(line + 3 >= map->size))
		return (0);
	i = 0;
	while (i < 4)
	{
		if (map->tab[line + i][col] != *(map->c))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		map->tab[line + i][col] = '.';
		i++;
	}
	return (1);
}

int	ft_clear_horiz_line(t_map *map, int line, int col)
{
	int	i;

	if ((col + 1 >= map->size) || (col + 2 >= map->size) || \
			(col + 3 >= map->size))
		return (0);
	i = 0;
	while (i < 4)
	{
		if (map->tab[line][col + i] != *(map->c))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		map->tab[line][col + i] = '.';
		i++;
	}
	return (1);
}

int	ft_clear_lvertic_up_left(t_map *map, int line, int col)
{
	if ((col - 1 < 0) || (line + 1 >= map->size) || \
			(line + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != *(map->c)) || (map->tab[line + 2][col] != *(map->c)) \
			|| (map->tab[line + 2][col - 1] != *(map->c)))
		return(0);
	map->tab[line][col] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 2][col] = '.';
	map->tab[line + 2][col - 1] = '.';
	return (1);
}

int	ft_clear_lvertic_down_left(t_map *map, int line, int col)
{
	if ((col + 1 >= map->size) || (line + 1 >= map->size) || \
			(line + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line][col + 1] != *(map->c)) || (map->tab[line + 1][col + 1] != *(map->c)) \
			|| (map->tab[line + 2][col + 1] != *(map->c)))
		return(0);
	map->tab[line][col] = '.';
	map->tab[line][col + 1] = '.';
	map->tab[line + 1][col + 1] = '.';
	map->tab[line + 2][col + 1] = '.';
	return (1);
}

int	ft_clear_lvertic_down_right(t_map *map, int line, int col)
{
	if ((col + 1 >= map->size) || (line + 1 >= map->size) || \
			(line + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line][col + 1] != *(map->c)) || (map->tab[line + 1][col] != *(map->c)) \
			|| (map->tab[line + 2][col] != *(map->c)))
		return(0);
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
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != *(map->c)) || (map->tab[line + 2][col] != *(map->c)) \
			|| (map->tab[line + 2][col + 1] != *(map->c)))
		return(0);
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
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != *(map->c)) || (map->tab[line][col + 1] != *(map->c)) \
			|| (map->tab[line][col + 2] != *(map->c)))
		return(0);
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
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col + 2] != *(map->c)) || (map->tab[line][col + 1] != *(map->c)) \
			|| (map->tab[line][col + 2] != *(map->c)))
		return(0);
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
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != *(map->c)) || (map->tab[line + 1][col + 1] != *(map->c)) \
			|| (map->tab[line + 1][col + 2] != *(map->c)))
		return(0);
	map->tab[line][col] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 1][col + 1] = '.';
	map->tab[line + 1][col + 2] = '.';
	return (1);
}

int	ft_clear_lhoriz_up_left(t_map *map, int line, int col)
{
	if ((col - 1 <= 0) || (col - 2 < 0) || \
			(line + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != *(map->c)) || (map->tab[line + 1][col - 1] != *(map->c)) \
			|| (map->tab[line + 1][col - 2] != *(map->c)))
		return(0);
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
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line][col + 1] != *(map->c)) || (map->tab[line + 1][col ] != *(map->c)) \
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
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line][col + 1] != *(map->c)) || (map->tab[line + 1][col + 1] != *(map->c)) \
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
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col - 1] != *(map->c)) || (map->tab[line + 1][col] != *(map->c)) \
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
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != *(map->c)) || (map->tab[line + 1][col + 1] != *(map->c)) \
			|| (map->tab[line + 2][col + 1] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line + 2][col + 1] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 1][col + 1] = '.';
	return (1);
}

int	ft_clear_t_up(t_map *map, int line, int col)
{
	if ((col - 1 < 0) || (col + 1 >= map->size) || (line + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line  + 1][col - 1] != *(map->c)) \
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
	if ((line + 2 >= map->size) || (col + 1 >= map->size) || (line + 1 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line  + 1][col] != *(map->c)) \
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
	if ((line + 1 >= map->size) || (col + 1 >= map->size) || (col + 2 >= map->size))
		return (0);
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line][col + 1] != *(map->c)) \
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
	if ((map->tab[line][col] != *(map->c)) || (map->tab[line + 1][col] != *(map->c)) \
			|| (map->tab[line + 1][col - 1] != *(map->c)) \
			|| (map->tab[line + 2][col] != *(map->c)))
		return (0);
	map->tab[line][col] = '.';
	map->tab[line + 1][col] = '.';
	map->tab[line + 1][col - 1] = '.';
	map->tab[line + 2][col] = '.';
	return (1);
}
