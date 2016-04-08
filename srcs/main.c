/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 01:43:20 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/07 04:26:32 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	main(int ac, char **av)
{
	int		nb_pieces;
	t_piece	pieces[MAX_PIECES + 1];

	if (ac == 2)
	{
		nb_pieces = ft_check_file(av[1], pieces);
		if (nb_pieces > 0)
		{
			printf("\nVALID FILE\n Nombre de pieces = %d", nb_pieces);
		}
		else
			printf("\nINVALID FILE or Error Closing file");
	}
	else
	{
		printf("\nUSAGE:");
	}
	return (0);
}
