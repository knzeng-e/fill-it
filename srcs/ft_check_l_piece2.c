/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_l_piece2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:46:47 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/07 04:13:44 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_check_horiz_hgauche(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i + 1 || tetro[1].column != j - 2)
		return (0);
	if (tetro[2].line != i + 1 || tetro[2].column != j - 1)
		return (0);
	if (tetro[3].line != i + 1 || tetro[3].column != j)
		return (0);
	pieces->forme = L_HORIZONTAL_HAUT_GAUCHE;
	printf("\nL-HORIZONTAL HAUT_GAUCHE ==> %d", pieces->forme);
	return (1);
}

int	ft_check_horiz_hdroit(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i + 1 || tetro[1].column != j)
		return (0);
	if (tetro[2].line != i + 1 || tetro[2].column != j + 1)
		return (0);
	if (tetro[3].line != i + 1 || tetro[3].column !=  j + 2)
		return (0);
	pieces->forme = L_HORIZONTAL_HAUT_DROIT;
	printf("\nL-HORIZONTAL HAUT_DROIT ==> %d", pieces->forme);
	return (1);
}

int	ft_check_horiz_bdroit(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i || tetro[1].column != j + 1)
		return (0);
	if (tetro[2].line != i || tetro[2].column != j + 2)
		return (0);
	if (tetro[3].line != i + 1 || tetro[3].column !=  j)
		return (0);
	pieces->forme = L_HORIZONTAL_BAS_DROIT;
	printf("\nL-HORIZONTAL BAS_DROIT ==> %d", pieces->forme);
	return (1);
}

int	ft_check_horiz_bgauche(t_tetro *tetro, t_piece *pieces)
{
	int	i;
	int	j;

	i = tetro[0].line;
	j = tetro[0].column;
	if (tetro[1].line != i || tetro[1].column != j + 1)
		return (0);
	if (tetro[2].line != i || tetro[2].column != j + 2)
		return (0);
	if (tetro[3].line != i + 1 || tetro[3].column !=  j + 2)
		return (0);
	pieces->forme = L_HORIZONTAL_BAS_GAUCHE;
	printf("\nL-HORIZONTAL BAS_GAUCHE ==> %d", pieces->forme);
	return (1);
}

int	ft_check_l_piece2(t_tetro *tetro, t_piece *pieces)
{
	return (ft_check_horiz_bgauche(tetro, pieces) || ft_check_horiz_bdroit(tetro, pieces) \
			|| ft_check_horiz_hdroit(tetro, pieces) || ft_check_horiz_hgauche(tetro, pieces));
}
