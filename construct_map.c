/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 00:21:49 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/27 17:38:39 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
 ** This function creates an empty map, this map will then be populated with
 ** the pieces.
 */
char	*create_empty_map(int size)
{
	char	*map;
	int		x;
	int 		y;

	map = ft_strnew((size + 1) * size);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			map[y * (size + 1) + x] = '.';
			x++;
		}
		map[y * (size + 1) + x] = '\n';
		y++;
	}
	map[(size + 1) * size] = '\0';
	return (map);
}

/*
 * Check if entry is filled checks if it is a #
 */
int		is_filled(int x, int y, t_tetris *t)
{
	return (((t->bit_rep >> (16 * (y + 1) - 1 - x)) & 1) ? 1 : 0);
}

/*
 * Print solved map.
 */
void	print_map(t_tetris *t, int count, int size)
{
	char	*str;
	int		x;
	int		y;
	
	str = create_empty_map(size);
	while (count)
	{
		y = -1;
		while (++y < t->height)
		{
			x = -1;
			while (++x < t->width)
				if (is_filled(x, y, t))
					str[(t->y + y) * (size + 1) + x + t->x] = t->letter;
		}
		t = t->next;
		count--;
	}
	str[(size + 1) * size] = '\0';
	ft_putstr(str);
	ft_strdel(&str);
}
