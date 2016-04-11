/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 01:43:20 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/11 11:21:27 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
		printf("\n%s", map->tab[i++]);
	printf("\n");
}

int		ft_init_map(t_map *map, int size_map, char c)
{
	int	i;
	int	j;

	if (!(map->c = (char*)malloc(sizeof(char))))
		return (ERROR_MALLOC);
	*(map->c) = c;
	map->size = size_map;
	map->clear = 0;
	if (!(map->tab = (char **)malloc(sizeof(char *) * map->size)))
		return (ERROR_MALLOC);
	i = 0;
	while (i < map->size)
	{
		if (!(map->tab[i] = (char *)malloc(sizeof(char) * map->size)))
		{
			free(map->tab);
			return (0);
		}
		j = 0;
		while (j < map->size)
			map->tab[i][j++] = '.';
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		nb_pieces;
	int		*pos;
	t_piece	pieces[MAX_PIECES + 1];
	t_map	*map;

	if (ac == 2)
	{
		nb_pieces = ft_check_file(av[1], pieces);
		if (nb_pieces > 0)
		{
			printf("\nVALID FILE\n Nombre de pieces = %d", nb_pieces);
			if (!(map = (t_map *)malloc(sizeof(t_map))) \
					|| !(pos = (int *)malloc(sizeof(int))))
				return (ERROR_MALLOC);
			*pos = 0;
			if (ft_init_map(map, 4, 'A') < 0)
			{
				free(map);
				return (ERROR_MALLOC);
			}
			map->nb_pieces = nb_pieces;
			ft_print_map(map);
			/*	ft_put_in_map(0,1, pieces, map);
				ft_print_map(map);
				map->clear = 1;
				ft_put_in_map(0,1, pieces, map);
				ft_print_map(map);
				ft_put_in_map(0,1, pieces, map);
				ft_print_map(map);*/

			insert(pieces, map, pos);
			//ft_print_map(map);
		}
		else
			printf("error");
	}
	else
	{
		printf("error");
	}
	return (0);
}
