/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:07:05 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/16 23:56:11 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

t_map	*ft_resize_map(t_map *old)
{
	t_map	*new;

	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	new->size = old->size + 1;
	ft_init_map(new, old->size + 1, 'A', old->nb_pieces);
	return (new);
}

int		ft_put_in_map(int line, int column, t_piece *piece, t_map *map)
{
	int	(*f[19])(t_map *, int, int);

	if (map->clear == 0)
		ft_set_insertfunctions(f);
	else
		ft_set_clearfunctions(f, map);
	return (f[piece->forme](map, line, column));
}

int		ft_get_next_position(t_piece *pieces, t_map *map, int line, int column)
{
	int		i;
	int		j;

	i = line;
	while (i < map->size)
	{
		j = column;
		while (j < map->size)
		{
			if (ft_put_in_map(i, j, pieces, map))
			{
				map->begin_line = i;
				map->begin_column = j;
				return ((i * map->size) + j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int		insert(t_piece *piece, t_map *map, int *current_piece)
{
	t_params	params;

	if (piece->forme == END)
		return (GAME_OVER);
	params.i = -1;
	while (++params.i < map->size)
	{
		params.j = -1;
		while (++params.j < map->size)
		{
			if ((params.ret = ft_put_in_map(params.i, params.j, piece, map)))
			{
				*current_piece = *current_piece + 1;
				if (insert(piece + 1, map, current_piece))
					return (1);
				else
				{
					*current_piece = *current_piece - 1;
					map->clear = 1;
					ft_put_in_map(params.i, params.j, piece, map);
				}
			}
		}
	}
	return (0);
}
