/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 21:40:40 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/03 04:07:24 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_IT_H
# define FILL_IT_H

# include <sys/types.h>
#include <sys/stat.h>
# include <fcntl.h>
#include <stdlib.h>
# include <unistd.h>

# define READ_LINE(x, t) read(x, t, 20)
# define READ_NL(x, t) read(x, t, 1)
# define MAX_PIECES 26
# define UNABLE_TO_OPEN -1
# define ERROR_ALLOCATION -2
# define INVALID_NB_TETRIMINOS 0
# define INVALID_DESCRIPTION 0
# define VALID_DESCRIPTION 1
# define VALID_DISPLAY 2

typedef struct	s_tetro
{
	int			line;
	int			column;
}				t_tetro;

int				ft_check_file(char *file);
int				ft_verif_piece(char *piece, t_tetro *display);
int				ft_check_display(t_tetro *display);

#endif
