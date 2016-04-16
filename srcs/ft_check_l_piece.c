/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_l_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:30:02 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/16 19:28:27 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_check_vertic_hgauche(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i + 1 || tetro[1].column != j)
		return (0);
	if (tetro[2].line != i + 2 || tetro[2].column != j - 1)
		return (0);
	if (tetro[3].line != i + 2 || tetro[3].column != j)
		return (0);
	pieces->forme = L_VERTIC_HAUT_GAUCHE;
	return (1);
}

int	ft_check_vertic_hdroit(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i + 1 || tetro[1].column != j)
		return (0);
	if (tetro[2].line != i + 2 || tetro[2].column != j)
		return (0);
	if (tetro[3].line != i + 2 || tetro[3].column != j + 1)
		return (0);
	pieces->forme = L_VERTIC_HAUT_DROIT;
	return (1);
}

int	ft_check_vertic_bdroit(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i || tetro[1].column != j + 1)
		return (0);
	if (tetro[2].line != i + 1 || tetro[2].column != j)
		return (0);
	if (tetro[3].line != i + 2 || tetro[3].column != j)
		return (0);
	pieces->forme = L_VERTIC_BAS_DROIT;
	return (1);
}

int	ft_check_vertic_bas_gauche(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i || tetro[1].column != j + 1)
		return (0);
	if (tetro[2].line != i + 1 || tetro[2].column != j + 1)
		return (0);
	if (tetro[3].line != i + 2 || tetro[3].column != j + 1)
		return (0);
	pieces->forme = L_VERTIC_BAS_GAUCHE;
	return (1);
}

int	ft_check_l_piece(t_tetro *tetro, t_piece *pieces)
{
	return (ft_check_vertic_hgauche(tetro, pieces) \
			|| ft_check_vertic_bas_gauche(tetro, pieces) \
			|| ft_check_vertic_bdroit(tetro, pieces) \
			|| ft_check_vertic_hdroit(tetro, pieces));
}
