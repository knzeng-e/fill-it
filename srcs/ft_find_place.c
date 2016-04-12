/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:07:05 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/12 21:51:00 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

t_map	*ft_resize_map(t_map *old)
{
	int		i;
	int		j;
	t_map	*new;

	printf("\n\tI'm being resized\n");
	i = 0;
	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	new->size = old->size + 1;
	ft_init_map(new, old->size + 1, *(old->c), old->begin_column, old->begin_column);
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

	printf("\n Finding position of piece [%d]==[pos %d]", pieces->forme, (*line * map->size) + *column);
	i = *line;
	while (i < map->size)
	{
		j = *column;
		while (j < map->size)
		{
			if (ft_put_in_map(i, j, pieces, map))
			{
				printf("\nInsertion en i = %d, j = %d", i, j);
				//ft_print_map(map);
				*line = i;
				*column = j;
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
	int	posi;
	int	i;
	int	j;

	if (piece->forme == END || *current_piece == map->nb_pieces)
		return (0);
	if (map->begin_column >= map->size)
	{
		map->begin_line += 1;
		map->begin_column = 0;
	}
	/** inserer la piece courante */
	printf("\nPiece_courante (current_piece >> %d [forme = %d]<<, LETTRE = %c)", *current_piece, piece->forme, *(map->c));
	if ((posi = ft_get_next_position(piece, map, &(map->begin_line), &(map->begin_column))) != -1)
	{
		printf("\nInsert OK!");
		piece->x = map->begin_line;
		piece->y = map->begin_column;
		map->begin_line = 0;
		map->begin_column = 0;
		printf("POSI = %d\n", posi);
		ft_print_map(map);
		*current_piece = *current_piece + 1;
		insert(++piece, map, current_piece);
	}
	else
	{
		printf("\n INSERTION  DE %d IMPOSSIBLE en position (<%d>,<%d>) - LETTRE => %c",piece->forme, piece->x, piece->y, *(map->c));
		--piece;
		*current_piece = *current_piece - 1;
		i = piece->x;
		j = piece->y;
		if (*(map->c) <= 'A')
		{
			map->begin_line = 0;
			map->begin_column = 0;
			printf("\n TIP TOP");
			*current_piece = *current_piece - 1;
			piece = &piece[0];
			map = ft_resize_map(map);
			ft_put_in_map(i, j, piece, map);
			ft_print_map(map);
		}
		else
		{
			//*(map->c) = *(map->c) - 1;
			printf("\n\tSuppression de la piece [ %c/%d ] de la position < line %d > - < column %d>", *map->c - 1, piece->forme, i, j);
			map->clear = 1;
			ft_put_in_map(i, j, piece, map);
			ft_print_map(map);
			map->begin_line = i;
			map->begin_column = j + 1;
		}

	//	insert(piece, map, current_piece);
	}
	insert(piece, map, current_piece);
	printf("\nLast posi = < %d >", posi);
	printf("\nout_of_while,i = %d, j = %d, piece = %d, map->size = %d", map->begin_line, map->begin_column, piece->forme, map->size);
	printf("\nSortie");
	return (1);
}
