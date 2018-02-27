/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:30:55 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/26 15:37:17 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
 ** This function creates an empty map, this map will then be populated with
 ** the pieces.
 */
char	*create_empty_map(int size)
{
	char	*map;
	int		x;
	int		y;

	map = ft_strnew((size + 1) * size);
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			map[y * (size + 1) + x] = '.';
		str[y * (size + 1) + x] = '\n';
	}
	return (map);
}

/*
 * Check if entry is filled
 */
int		is_filled(int x, int y, t_tetris_map *t)
{
	return (((t->value >> (16 * (y + 1) - 1 - x)) & 1) ? 1 : 0);
}

/*
 * Print solved map.
 */
void	print_map(t_tetris_map *t, int count, int size)
{
	char	*map;
	int		x;
	int		y;

	while (count)
	{
		y = -1;
		while (++y < t->height)
		{
			x = -1;
			while (++x < t->width)
				if (is_filled(x, y, t))
					str[]
		}
	}
}
