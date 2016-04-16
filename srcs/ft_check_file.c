/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 21:56:26 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/16 22:27:08 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_parse_file(int fd, struct s_params *par, t_piece *pieces)
{
	char	current_piece[21];
	t_tetro	*tetro[MAX_PIECES];

	while ((par->lus = GET_PIECE(fd, current_piece)))
	{
		par->line_at_end = 0;
		if (!(tetro[par->cpt] = (t_tetro *)malloc(sizeof(t_tetro) * 4)))
			return (ERROR_ALLOCATION);
		current_piece[par->lus] = '\0';
		if ((par->cpt >= 26) \
				|| !(ft_verif_piece(current_piece, &pieces[par->cpt])))
			return (INVALID_DESCRIPTION);
		par->lus = READ_NL(fd, current_piece);
		current_piece[par->lus] = '\0';
		if (par->lus && current_piece[0] != '\n')
			return (INVALID_DESCRIPTION);
		par->line_at_end = (par->lus != 0) ? 1 : 0;
		par->cpt++;
	}
	if (par->line_at_end)
	{
		current_piece[par->lus] = '\0';
		return (INVALID_DESCRIPTION);
	}
	return (1);
}

int	ft_check_file(char *file, t_piece *pieces)
{
	struct s_params	par;
	int				fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (UNABLE_TO_OPEN);
	par.cpt = 0;
	if (ft_parse_file(fd, &par, pieces) < 0)
		return (INVALID_DESCRIPTION);
	pieces[par.cpt].forme = END;
	par.cpt = ((close(fd) != -1) ? par.cpt : -1);
	return (par.cpt);
}
