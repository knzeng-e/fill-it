/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 21:40:40 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/10 02:06:50 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H

# include <sys/types.h>
#include <sys/stat.h>
# include <fcntl.h>
#include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define NB_CARAC_IN_PIECE 20
# define GET_PIECE(x, t) read(x, t, NB_CARAC_IN_PIECE)
# define READ_NL(x, t) read(x, t, 1)
# define MAX_PIECES 26
# define UNABLE_TO_OPEN -1
# define ERROR_ALLOCATION -2
# define INVALID_NB_TETRIMINOS 0
# define INVALID_DESCRIPTION 0
# define NO 0
# define YES 1
# define VALID_DESCRIPTION 1
# define INVALID_DISPLAY -3
# define VALID_DISPLAY 2
# define INSERT_SUCCESS 3
# define ERROR_MALLOC -4

typedef enum		e_type_piece
{
					SQUARE,
					HORIZONTAL,
					VERTICAL,
					L_VERTIC_HAUT_GAUCHE,
					L_VERTIC_BAS_DROIT,
					L_VERTIC_BAS_GAUCHE,
					L_VERTIC_HAUT_DROIT,
					L_HORIZONTAL_BAS_DROIT,
					L_HORIZONTAL_BAS_GAUCHE,
					L_HORIZONTAL_HAUT_DROIT,
					L_HORIZONTAL_HAUT_GAUCHE,
					Z_HORIZONTAL_RIGHT,
					Z_HORIZONTAL_LEFT,
					Z_VERTICAL_LEFT,
					Z_VERTICAL_RIGHT,
					T_UP,
					T_RIGHT,
					T_DOWN,
					T_LEFT
}					t_forme;

typedef struct		s_tetro
{
	int				line;
	int				column;
}					t_tetro;

typedef struct		s_piece
{
	t_tetro			tetro[4];
	t_forme			forme;
	int				is_inserted;
}					t_piece;

typedef struct		s_map
{
	int				size;
	int				clear;
	char			**tab;
	char			*c;
}					t_map;

int					ft_check_file(char *file, t_piece *piece);
int					ft_verif_piece(char *piece, t_piece *display);
int					ft_check_display(t_tetro *tetro, t_piece *piece);
int					ft_check_line_and_square(t_tetro *tetro, t_piece *piece);
int					ft_check_l_piece(t_tetro *tetro, t_piece *piece);
int					ft_check_l_piece2(t_tetro *tetro, t_piece *piece);
int					ft_check_t_piece(t_tetro *tetro, t_piece *piece);
int					ft_check_z_piece(t_tetro *tetro, t_piece *piece);
int					ft_clear_square(t_map *map, int line, int col);
int					ft_clear_vertic_line(t_map *map, int line, int col);
int					ft_clear_horiz_line(t_map *map, int line, int col);
int					ft_clear_lvertic_up_left(t_map *map, int line, int col);
int					ft_clear_lvertic_down_left(t_map *map, int line, int col);
int					ft_clear_lvertic_down_right(t_map *map, int line, int col);
int					ft_clear_lvertic_up_right(t_map *map, int line, int col);
int					ft_clear_lhoriz_down_right(t_map *map, int line, int col);
int					ft_clear_lhoriz_down_left(t_map *map, int line, int col);
int					ft_clear_lhoriz_up_right(t_map *map, int line, int col);
int					ft_clear_lhoriz_up_left(t_map *map, int line, int col);
int					ft_clear_zhoriz_right(t_map *map, int line, int col);
int					ft_clear_zhoriz_left(t_map *map, int line, int col);
int					ft_clear_zvertic_left(t_map *map, int line, int col);
int					ft_clear_zvertic_right(t_map *map, int line, int col);
int					ft_clear_t_up(t_map *map, int line, int col);
int					ft_clear_t_right(t_map *map, int line, int col);
int					ft_clear_t_down(t_map *map, int line, int col);
int					ft_clear_t_left(t_map *map, int line, int col);
int					ft_put_in_map(int line, int column, t_piece *piece, \
		t_map *map);
int					ft_init_map(t_map *map, int size_map, char c);
int					insert(t_piece *piece, t_map *map, int pos);
t_map				*ft_resize_map(t_map *old);
void				ft_print_map(t_map *map);
//int					(*ft_put_forme)(t_forme, t_map *, int, int)[17];
char				*ft_resolve(t_piece *pieces, int *nb_pieces, char *map);
#endif
