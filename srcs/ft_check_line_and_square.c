/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line_and_square.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 17:31:16 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/16 19:26:45 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_check_line_horiz(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	cpt;

	i = tetro[0].line;
	cpt = 1;
	while (cpt < 4)
		if (i != tetro[cpt++].line)
			return (0);
	pieces->forme = HORIZONTAL;
	return (1);
}

int	ft_check_line_vertic(t_tetro *tetro, t_piece *pieces)
{
	int	j;
	int	cpt;

	j = tetro[0].column;
	cpt = 1;
	while (cpt < 4)
		if (j != tetro[cpt++].column)
			return (0);
	pieces->forme = VERTICAL;
	return (1);
}

int	ft_check_square(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if ((i != tetro[1].line) || (tetro[1].column != j + 1))
		return (0);
	if ((tetro[2].line != i + 1) || (tetro[2].column != j))
		return (0);
	if ((tetro[3].line != i + 1) || (tetro[3].column != j + 1))
		return (0);
	pieces->forme = SQUARE;
	return (1);
}

int	ft_check_line_and_square(t_tetro *tetro, t_piece *pieces)
{
	if (!(ft_check_line_vertic(tetro, pieces) || \
				ft_check_line_horiz(tetro, pieces)))
		return (ft_check_square(tetro, pieces));
	return (1);
}
