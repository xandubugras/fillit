/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_tetris_block.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:38:12 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/27 19:00:41 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Variable definitions
** char *map - the character representation of the tetrimino
** max_min_pos, pos - holds the min and max x,y indices of the tetrimino
** block_bit_representation - holds the bit representation of the tetrimino
*/

/*
** This function returns the min and max indices of the tetrimino.
*/

void		get_min_max_x_y(const char *map, int *max_min_pos)
{
	int i;

	i = 0;
	max_min_pos[0] = 3;
	max_min_pos[1] = 0;
	max_min_pos[2] = 3;
	max_min_pos[3] = 0;
	while (map[i])
	{
		if (map[i] == '#')
		{
			if (i % 5 < max_min_pos[0])
				max_min_pos[0] = i % 5;
			if (i % 5 > max_min_pos[1])
				max_min_pos[1] = i % 5;
			if (i / 5 < max_min_pos[2])
				max_min_pos[2] = i / 5;
			if (i / 5 > max_min_pos[3])
				max_min_pos[3] = i / 5;
		}
		i++;
	}
}

/*
** This function returns a bit representation of the tetrimino.
*/

uint64_t	get_tetris_bit_value(const char *map, int height, int width,
		int *m)
{
	int			x;
	int			y;
	uint64_t	block_bit_representation;

	y = 0;
	block_bit_representation = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[(m[0] + x) + ((m[2] + y) * 5)] == '#')
				block_bit_representation |= (1L << (16 * (y + 1) - 1 - x));
			x++;
		}
		y++;
	}
	return (block_bit_representation);
}

t_tetris	*create_tetris_struct(const char *map, const char letter)
{
	t_tetris	*new;
	int			pos[4];

	new = (t_tetris *)malloc(sizeof(t_tetris));
	get_min_max_x_y(map, pos);
	new->width = pos[1] - pos[0] + 1;
	new->height = pos[3] - pos[2] + 1;
	new->letter = letter;
	new->bit_rep = get_tetris_bit_value(map, new->height, new->width, pos);
	new->prev = NULL;
	new->next = NULL;
	new->x = 0;
	new->y = 0;
	return (new);
}
