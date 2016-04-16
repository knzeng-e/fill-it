/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:07:05 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/16 01:06:06 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

t_map	*ft_resize_map(t_map *old)
{
	//int	i;
	//int	j;
	t_map	*new;

	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	//ft_print_map(old);
	//printf("\n");
	new->size = old->size + 1;
	ft_init_map(new, old->size + 1, 'A', old->nb_pieces);
	/*i = 0;
	while (i < old->size)
	{
		j = 0;
		while (j < old->size)
		{
			new->tab[i][j] = old->tab[i][j];
			j++;
		}
		i++;
	}
	new->tab[i][++j] = '\0';*/
//	printf("AFTER RESIZE\n");
//	ft_print_map(new);
	//printf("\n");
	return (new);
}

int		ft_put_in_map(int line, int column, t_piece *piece, t_map *map)
{
	int	(*f[19])(t_map *, int, int);

	if (map->clear == 0)
	{
		f[0] = &ft_insert_square;
		f[1] = &ft_insert_horiz_line;
		f[2] = &ft_insert_vertic_line;
		f[3] = &ft_insert_lvertic_up_left;
		f[4] = &ft_insert_lvertic_down_right;
		f[5] = &ft_insert_lvertic_down_left;
		f[6] = &ft_insert_lvertic_up_right;
		f[7] = &ft_insert_lhoriz_down_right;
		f[8] = &ft_insert_lhoriz_down_left;
		f[9] = &ft_insert_lhoriz_up_right;
		f[10] = &ft_insert_lhoriz_up_left;
		f[11] = &ft_insert_zhoriz_right;
		f[12] = &ft_insert_zhoriz_left;
		f[13] = &ft_insert_zvertic_left;
		f[14] = &ft_insert_zvertic_right;
		f[15] = &ft_insert_t_up;
		f[16] = &ft_insert_t_right;
		f[17] = &ft_insert_t_down;
		f[18] = &ft_insert_t_left;
	}
	else
	{
		(*map->c)--;
		f[0] = &ft_clear_square;
		f[1] = &ft_clear_horiz_line;
		f[2] = &ft_clear_vertic_line;
		f[3] = &ft_clear_lvertic_up_left;
		f[4] = &ft_clear_lvertic_down_right;
		f[5] = &ft_clear_lvertic_down_left;
		f[6] = &ft_clear_lvertic_up_right;
		f[7] = &ft_clear_lhoriz_down_right;
		f[8] = &ft_clear_lhoriz_down_left;
		f[9] = &ft_clear_lhoriz_up_right;
		f[10] = &ft_clear_lhoriz_up_left;
		f[11] = &ft_clear_zhoriz_right;
		f[12] = &ft_clear_zhoriz_left;
		f[13] = &ft_clear_zvertic_left;
		f[14] = &ft_clear_zvertic_right;
		f[15] = &ft_clear_t_up;
		f[16] = &ft_clear_t_right;
		f[17] = &ft_clear_t_down;
		f[18] = &ft_clear_t_left;
		map->clear = 0;
	}
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
	int	i;
	int	j;
	int	ret;



	if (piece->forme == END)
		return (GAME_OVER);
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if ((ret = ft_put_in_map(i, j, piece, map)))
			{
				*current_piece = *current_piece + 1;
				//piece->x = i;
				//piece->y = j;
				if (insert(piece + 1, map, current_piece))
					return (1);
				else
				{
					//printf("before\n");
					//ft_print_map(map);
					//printf("\n");
					*current_piece = *current_piece - 1;
					map->clear = 1;
					ft_put_in_map(i, j, piece, map);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
