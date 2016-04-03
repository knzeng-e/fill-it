/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 01:43:20 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/03 01:44:32 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	check;

	if (ac >= 2)
	{
		check = ft_check_file(av[1]);
		if (check > 0)
			printf("\nVALID FILE");
		else
			printf("\nINVALID FILE");
	}
	return (0);
}
