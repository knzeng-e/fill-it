/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:07:05 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/10 15:33:26 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

t_map	*ft_resize_map(t_map *old)
{
	int		i;
	int		j;
	t_map	*new;

	i = 0;
	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	new->size = old->size + 1;
	ft_init_map(new, old->size + 1, *(old->c));
	while (i < old->size)
	{
		j = 0;
		while (j < old->size)
		{
			new->tab[i][j] = old->tab[i][j];
			j++;
		}
		printf("\n%s", new->tab[i]);
		i++;
	}
	return (new);
}

int		ft_put_in_map(int line, int column, t_piece *piece, t_map *map)
{
	int	(*f[19])(t_map *, int, int);

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
	return (f[piece->forme](map, line, column));
}

int		insert(t_piece *piece, t_map *map, int pos)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (piece == NULL)
		return (0);
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			pos = (i * map->size) + j;
			if (ft_put_in_map(i, j, piece, map))
				insert(++piece, map, pos + 1);
			else
				j++;
		}
		i++;
	}
	if (i == map->size)
	{
		map = ft_resize_map(map);
		return (insert(piece, map, pos));
	}
	return (1);
}
