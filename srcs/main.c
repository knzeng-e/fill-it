/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 01:43:20 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/16 01:55:28 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int		ft_get_next_position(t_piece *pieces, t_map *map, int line, int column);
int		ft_put_in_map(int i, int j, t_piece *piece, t_map *map);

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
		printf("%s\n", map->tab[i++]);
}

int		ft_init_map(t_map *map, int size_map, char c, int nb_pieces)
{
	int	i;
	int	j;

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
	i = 0;
	while (i < map->size)
	{
		if (!(map->tab[i] = (char *)malloc(sizeof(char) * map->size + 1)))
		{
			free(map->tab);
			return (0);
		}
		j = 0;
		while (j < map->size)
			map->tab[i][j++] = '.';
		map->tab[i][j] = '\0';
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		nb_pieces;
	int		*pos;
	int		ret;
	//int		out;
	t_piece	pieces[MAX_PIECES + 1];
	t_map	*map;

	if (ac == 2)
	{
		nb_pieces = ft_check_file(av[1], pieces);
		if (nb_pieces > 0)
		{
			if (!(map = (t_map *)malloc(sizeof(t_map))) \
					|| !(pos = (int *)malloc(sizeof(int))))
				return (ERROR_MALLOC);
			*pos = 0;
			if (ft_init_map(map, 3, 'A', nb_pieces) < 0)
			{
				free(map);
				return (ERROR_MALLOC);
			}
			map->nb_pieces = nb_pieces;
			//ft_print_map(map);
			while (!(ret = insert(pieces, map, pos)))
				map = ft_resize_map(map);
			ft_print_map(map);
		/*	ret = 0;
			  while (ret < nb_pieces)
			  {
			  out = ft_get_next_position(pieces + ret, map, 0,0);
			  printf(" out = %d, Forme ==> %d\n", out, pieces[ret].forme);
			  ft_print_map(map);
			  printf("Test Suppression >>>>\n");
			  map->clear = 1;
			  ft_put_in_map((out / map->size), (out % map->size), pieces + ret, map);
			  ft_print_map(map);
			  printf("\nNext ...>>>\n");
			  ret++;
			  }*/
		}
		else
			printf("error");
	}
	else
		printf("error");
	return (0);
}
