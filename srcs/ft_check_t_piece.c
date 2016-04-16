/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_t_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 00:02:30 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/16 22:31:08 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_check_vertical_gauche(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].column != j - 1 || tetro[1].line != i + 1)
		return (0);
	if (tetro[2].line != i + 1 || tetro[2].column != j)
		return (0);
	if (tetro[3].line != i + 2 || tetro[3].column != j)
		return (0);
	pieces->forme = T_LEFT;
	return (1);
}

int	ft_check_vertical_droit(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].column != j || tetro[1].line != i + 1)
		return (0);
	if (tetro[2].line != i + 1 || tetro[2].column != j + 1)
		return (0);
	if (tetro[3].line != i + 2 || tetro[3].column != j)
		return (0);
	pieces->forme = T_RIGHT;
	return (1);
}

int	ft_check_up(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i + 1 || tetro[1].column != j - 1)
		return (0);
	if (tetro[2].line != i + 1 || tetro[2].column != j)
		return (0);
	if (tetro[3].line != i + 1 || tetro[3].column != j + 1)
		return (0);
	pieces->forme = T_UP;
	return (1);
}

int	ft_check_down(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i || tetro[1].column != j + 1)
		return (0);
	if (tetro[2].line != i || tetro[2].column != j + 2)
		return (0);
	if (tetro[3].line != i + 1 || tetro[3].column != j + 1)
		return (0);
	pieces->forme = T_DOWN;
	return (1);
}

int	ft_check_t_piece(t_tetro *tetro, t_piece *pieces)
{
	return (ft_check_down(tetro, pieces) || ft_check_up(tetro, pieces) \
			|| ft_check_vertical_droit(tetro, pieces) \
			|| ft_check_vertical_gauche(tetro, pieces));
}
