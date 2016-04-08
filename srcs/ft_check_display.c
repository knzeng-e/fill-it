/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 03:57:26 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/07 04:46:42 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_check_display(t_tetro *tetro, t_piece *pieces)
{
	if ((ft_check_line_and_square(tetro, pieces) || ft_check_t_piece(tetro, pieces) ||\
				ft_check_l_piece(tetro, pieces) || ft_check_z_piece(tetro, pieces) || \
				ft_check_l_piece2(tetro, pieces)))
	{
		pieces->is_inserted = NO;
		return (VALID_DISPLAY);
	}
	return (INVALID_DISPLAY);
}
