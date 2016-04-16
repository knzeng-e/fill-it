/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 23:27:40 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/16 23:29:13 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

void	ft_set_clearfunctions(int (*f[19])(t_map *, int, int), t_map *map)
{
	(*map->c)--;
	f[0] = &ft_clear_square;
	f[1] = &ft_clear_horiz_line;
	f[2] = &ft_clear_vertic_line;
	f[3] = &ft_clear_lvertic_up_left;
	f[4] = &ft_clear_lvertic_down_right;
	f[5] = &ft_clear_lvertic_down_left;
	f[6] = &ft_clear_lvertic_up_right;
	f[7] = &ft_clear_lhoriz_down_right;
	f[8] = &ft_clear_lhoriz_down_left;
	f[9] = &ft_clear_lhoriz_up_right;
	f[10] = &ft_clear_lhoriz_up_left;
	f[11] = &ft_clear_zhoriz_right;
	f[12] = &ft_clear_zhoriz_left;
	f[13] = &ft_clear_zvertic_left;
	f[14] = &ft_clear_zvertic_right;
	f[15] = &ft_clear_t_up;
	f[16] = &ft_clear_t_right;
	f[17] = &ft_clear_t_down;
	f[18] = &ft_clear_t_left;
	map->clear = 0;
}

void	ft_set_insertfunctions(int (*f[19])(t_map *, int, int))
{
	f[0] = &ft_insert_square;
	f[1] = &ft_insert_horiz_line;
	f[2] = &ft_insert_vertic_line;
	f[3] = &ft_insert_lvertic_up_left;
	f[4] = &ft_insert_lvertic_down_right;
	f[5] = &ft_insert_lvertic_down_left;
	f[6] = &ft_insert_lvertic_up_right;
	f[7] = &ft_insert_lhoriz_down_right;
	f[8] = &ft_insert_lhoriz_down_left;
	f[9] = &ft_insert_lhoriz_up_right;
	f[10] = &ft_insert_lhoriz_up_left;
	f[11] = &ft_insert_zhoriz_right;
	f[12] = &ft_insert_zhoriz_left;
	f[13] = &ft_insert_zvertic_left;
	f[14] = &ft_insert_zvertic_right;
	f[15] = &ft_insert_t_up;
	f[16] = &ft_insert_t_right;
	f[17] = &ft_insert_t_down;
	f[18] = &ft_insert_t_left;
}
