/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 01:43:20 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/16 19:22:29 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int		ft_fill_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size)
	{
		if (!(map->tab[i] = (char *)malloc(sizeof(char) * map->size + 1)))
		{
			free(map->tab);
			return (ERROR_INIT_MAP);
		}
		j = 0;
		while (j < map->size)
			map->tab[i][j++] = '.';
		map->tab[i][j] = '\0';
		i++;
	}
	return (INIT_SUCCESS);
}

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
		ft_putendl(map->tab[i++]);
}

int		ft_init_map(t_map *map, int size_map, char c, int nb_pieces)
{
	if (!(map->c = (char*)malloc(sizeof(char))))
		return (ERROR_MALLOC);
	*(map->c) = c;
	map->size = size_map;
	map->clear = 0;
	map->begin_line = 0;
	map->begin_column = 0;
	map->nb_pieces = nb_pieces;
	if (!(map->tab = (char **)malloc(sizeof(char *) * map->size)))
		return (ERROR_MALLOC);
	return (ft_fill_map(map));
}

void	ft_resolve(t_piece *pieces, t_map *map, int nb_pieces)
{
	int	ret;
	int	pos;

	pos = 0;
	map->nb_pieces = nb_pieces;
	while (!(ret = insert(pieces, map, &pos)))
		map = ft_resize_map(map);
	ft_print_map(map);
}

int		main(int ac, char **av)
{
	int		nb_pieces;
	t_piece	pieces[MAX_PIECES + 1];
	t_map	*map;

	if (ac == 2)
	{
		nb_pieces = ft_check_file(av[1], pieces);
		if (nb_pieces > 0)
		{
			if (!(map = (t_map *)malloc(sizeof(t_map))))
				return (ERROR_MALLOC);
			if (ft_init_map(map, 3, 'A', nb_pieces) < 0)
			{
				free(map);
				return (ERROR_MALLOC);
			}
			ft_resolve(pieces, map, nb_pieces);
		}
		else
			ft_putstr("error");
	}
	else
		ft_putstr("error");
	return (0);
}
