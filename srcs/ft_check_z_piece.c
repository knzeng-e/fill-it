/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_z_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 04:07:17 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/14 20:32:33 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_check_un(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i || tetro[1].column != j + 1)
		return (0);
	if (tetro[2].line != i + 1 || tetro[2].column != j - 1)
		return (0);
	if (tetro[3].line != i + 1 || tetro[3].column != j)
		return (0);
	pieces->forme = Z_HORIZONTAL_RIGHT;
	return (1);
}

int	ft_check_deux(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i || tetro[1].column != j + 1)
		return (0);
	if (tetro[2].line != i + 1 || tetro[2].column != j + 1)
		return (0);
	if (tetro[3].line != i + 1 || tetro[3].column != j + 2)
		return (0);
	pieces->forme = Z_HORIZONTAL_LEFT;
	return (1);
}

int	ft_check_trois(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i + 1 || tetro[1].column != j)
		return (0);
	if (tetro[2].line != i + 1 || tetro[2].column != j + 1)
		return (0);
	if (tetro[3].line != i + 2 || tetro[3].column != j + 1)
		return (0);
	pieces->forme = Z_VERTICAL_RIGHT;
	return (1);
}

int	ft_check_quatre(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if ((tetro[1].line != i + 1) || (tetro[1].column != j - 1))
		return (0);
	if ((tetro[2].line != i + 1) || (tetro[2].column != j))
		return (0);
	if ((tetro[3].line != i + 2) || (tetro[3].column != j - 1))
		return (0);
	pieces->forme = Z_VERTICAL_LEFT;
	return (1);
}

int	ft_check_z_piece(t_tetro *tetro, t_piece *pieces)
{
	return (ft_check_un(tetro, pieces) || ft_check_deux(tetro, pieces) || \
			ft_check_trois(tetro, pieces) || ft_check_quatre(tetro, pieces));
}
