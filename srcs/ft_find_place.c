/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:07:05 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/11 11:32:11 by knzeng-e         ###   ########.fr       */
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

		printf("\nVal c = %c", *(map->c));
		(*map->c)--;
		printf("\nVal c = %c", *(map->c));
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

int		ft_get_next_position(t_piece *pieces, t_map *map, int *line, int *column)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (ft_put_in_map(i, j, pieces, map))
			{
				//ft_print_map(map);
				*line = i;
				*column = j;
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
	int		i;
	int		j;
	int		posi;

	i = 0;
	j = 0;
	if (piece == NULL)
		return (0);
	/** inserer la piece courante */
	printf("\nPiece_courante (current_piece >> %d <<)", *current_piece);
	while (*current_piece != map->nb_pieces)
	{
		if ((posi = ft_get_next_position(piece, map, &i, &j) != -1))
		{
			map->last_i = i;
			map->last_j = j;
			ft_print_map(map);
			printf("\nPOSI = %d", posi);
			*current_piece = *current_piece + 1;
			insert(++piece, map, current_piece);
		}
		else
		{
			if (*current_piece == 0)
			{
				printf("\nVal i = %d, val j = %d", i, j);
				map = ft_resize_map(map);
				ft_print_map(map);
				printf("\nVal i = %d, val j = %d", i, j);
			}
			else
			{
				printf("\n\tVal before c = %c\n\ti = %d, j = %d\n\tPIECE A KILL >> %d", *(map->c), i, j, piece->forme);
				map->clear = 1;
				*current_piece = *current_piece - 1;
				ft_put_in_map(map->last_i, map->last_j, --piece, map);
				//insert(piece, map, current_piece);
				printf("\n\tVal after c = %c\n\ti = %d, j = %d", *(map->c), map->last_i, map->last_j);
				ft_print_map(map);

			}
		}







		/*	while (i < map->size)
			{
			j = 0;
			printf("\nCurrr-Pir ==> %d", *current_piece);
			while (j < map->size)
			{
			printf("\nCurrr-Pie ==> %d", *current_piece);
			if ((posi = ft_put_in_map(i, j, piece, map)))
			{
			printf("\ni = %d, j = %d, piece = %d, map->size = %d, current_piece = %d", i, j, piece->forme, map->size, *current_piece);
			ft_print_map(map);
		 *current_piece = *current_piece + 1;
		 insert(piece + (*current_piece), map, current_piece);
		 }
		 else if (*current_piece > 0)
		 {
		 printf("\nPosition_to_clear ==> i = %d, j = %d", i , j);
		 map->clear = 1;
		 ft_put_in_map(i, j, piece, map);
		//(*current_piece)--;
		insert((piece + (*current_piece - 1)), map, current_piece);
		ft_put_in_map(i, j, piece, map);
		//	map = ft_resize_map(map);
		ft_print_map(map);

		}
		j++;
		}
		i++;
		}*/

		printf("\nout_of_while,i = %d, j = %d, piece = %d, map->size = %d", i, j, piece->forme, map->size);
		}
	printf("\nSortie");
	return (1);
}
