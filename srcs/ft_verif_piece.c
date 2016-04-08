/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 01:47:30 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/07 04:33:46 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_verif_piece(char *piece, t_piece *display)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while (i < 20)
	{
		j = -1;
		while (++j < 4)
		{
			if (piece[i] != '#' && piece[i] != '.')
				return (INVALID_DESCRIPTION);
			if (piece[i] == '#')
			{
				if (nb == 4)
					return (INVALID_NB_TETRIMINOS);
				display->tetro[nb].line = (i / 5);
				display->tetro[nb++].column = j;
			}
			i++;
		}
		if (piece[i++] != '\n')
			return (INVALID_DESCRIPTION);
	}
	return ((nb == 4) && (ft_check_display(display->tetro, display) > 0));
}
