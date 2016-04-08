/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 21:40:40 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/07 04:46:35 by knzeng-e         ###   ########.fr       */
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

typedef enum	e_type_piece
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
}				t_forme;

typedef struct	s_tetro
{
	int			line;
	int			column;
}				t_tetro;

typedef struct	s_piece
{
	t_tetro		tetro[4];
	t_forme		forme;
	int			is_inserted;
}				t_piece;

int				ft_check_file(char *file, t_piece *piece);
int				ft_verif_piece(char *piece, t_piece *display);
int				ft_check_display(t_tetro *tetro, t_piece *piece);
int				ft_check_line_and_square(t_tetro *tetro, t_piece *piece);
int				ft_check_l_piece(t_tetro *tetro, t_piece *piece);
int				ft_check_l_piece2(t_tetro *tetro, t_piece *piece);
int				ft_check_t_piece(t_tetro *tetro, t_piece *piece);
int				ft_check_z_piece(t_tetro *tetro, t_piece *piece);

#endif
