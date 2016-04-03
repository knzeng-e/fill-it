/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 01:47:30 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/03 03:55:19 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"
#include <stdio.h>

int	ft_verif_piece(char *piece, t_tetro *display)
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
				display[nb].line = i;
				display[nb++].column = j;
			}
			i++;
		}
		if (piece[i++] != '\n' || !ft_check_display(display))
			return (INVALID_DESCRIPTION);
	}
	return (VALID_DESCRIPTION);
}
