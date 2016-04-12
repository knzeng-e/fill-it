/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 21:56:26 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/12 20:17:28 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_check_file(char *file, t_piece *pieces)
{
	int		fd;
	int		lus;
	int		i;
	int		line_at_end;
	t_tetro	*tetro[MAX_PIECES];
	char	current_piece[21];

	if ((fd = open(file, O_RDONLY)) == -1)
		return (UNABLE_TO_OPEN);
	i = 0;
	while ((lus = GET_PIECE(fd, current_piece)))
	{
		line_at_end = 0;
		if (!(tetro[i] = (t_tetro *)malloc(sizeof(t_tetro) * 4)))
			return (ERROR_ALLOCATION);
		current_piece[lus] = '\0';
		if ((i >= 26) || !(ft_verif_piece(current_piece, &pieces[i])))
			return (INVALID_DESCRIPTION);
		lus = READ_NL(fd, current_piece);
		current_piece[lus] = '\0';
		if (lus && current_piece[0] != '\n')
			return (INVALID_DESCRIPTION);
		line_at_end = (lus != 0) ? 1 : 0;
		i++;
	}
	if (line_at_end)
	{
		current_piece[lus] = '\0';
		return (INVALID_DESCRIPTION);
	}
	pieces[i].forme = END;
	i = ((close(fd) != -1) ? i : -1);
	return (i);
}
