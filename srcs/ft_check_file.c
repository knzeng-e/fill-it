/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 21:56:26 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/04/03 04:20:24 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"

int	ft_check_file(char *file)
{
	int		fd;
	int		lus;
	int		i;
	t_tetro	*display[MAX_PIECES];
	char	piece[21];

	if ((fd = open(file, O_RDONLY)) == -1)
		return (UNABLE_TO_OPEN);
	i = 0;
	while ((lus = READ_LINE(fd, piece)))
	{
		if(!(display[i] = (t_tetro *)malloc(sizeof(t_tetro) * 4)))
				return (ERROR_ALLOCATION);
		piece[lus] = '\0';
		if (!(ft_verif_piece(piece, display[i++])))
			return (INVALID_DESCRIPTION);
		lus = READ_NL(fd, piece);
		piece[lus] = '\0';
			if (lus && piece[0] != '\n')
				return (INVALID_DESCRIPTION);
	}
	return (VALID_DESCRIPTION +  close(fd));
}
