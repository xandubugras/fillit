/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:27:28 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/27 18:23:22 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
 * checked with the beast's file and bug remains
 * This function check whether the piece could fit on the board given its
 * position. This is done by using the bitwise AND operator between the map
 * shifted by the y index, and the bit representation of the block
 * shifted by the x position.
 */
int		piece_fits_in_board(t_tetris *block, uint16_t *bit_map)
{
	return (!(*(uint64_t *)(block->y + bit_map) &
				(block->bit_rep >> block->x))); //if the block has a 1(which means #) in the same position as the 
}

/*
 * This function serves to either add or remove a piece in the board; if it is
 * present it will be removed, if not then added. This is done by using the XOR
 * operator on the bit_map and the bitwise representation of the piece to be
 * added. XOR is used to avoid any overlap.
 */
void	switch_piece_on_off(t_tetris *block, uint16_t *bit_map)
{
	*(uint64_t *)(block->y + bit_map) ^= (block->bit_rep >> block->x);
}

/*
 * This function attempts all tetris pieces on a board of size (size);
 * It does so by iterating over each position of the board, if the current
 * piece fits on the board, i.e. placing it on the board does not cause any
 * conflicts we place it. We then check if all blocks fit on the board.
 * If they do the map has been solved. Otherwise, we return to the last piece
 * placed (prior to the failure) and shift it's position by 1 to the right.
 */
int		solve_bit_map(t_tetris *block, int size, uint16_t *bit_map)
{
	int pos;

	pos = 0;
	if (!(block)) //checking if its a hashtag
	{
		return (1);
	}
	if (block->next) //tests if its not the last
		pos = block->next->x + (block->next->y * size); //set the buffer to the previous position
	else
		pos = 0; //if its the first, start at zero
	block->y = (pos / size) - 1; //position it should be in the string
	while (++(block->y) <= (size - block->height)) //dont go outside the size possibility
	{
		block->x = (block->y == (pos / size) ? (pos % size) : 0); // checks if its the first time.
		while ((block->x) <= size - block->width) // not exceed range on horizontal
		{
			if (piece_fits_in_board(block, bit_map)) //checks with & if there is a one in the same place
			{ //if it finds a position thats free i
				switch_piece_on_off(block, bit_map);//switches ones and zeroes
				if (block->next)
				{
					if (solve_bit_map(block->next, size, bit_map))
					{
						return (1);
					}
				}
				else
				{
						return (1);
				}
				switch_piece_on_off(block, bit_map);
			}
			(block->x)++;
		}
	}
	block->x = 0;
	block->y = 0;
	return (0);
}

/*
 * This function works by attempting to fit all the pieces, on the smallest
 * board possible. If all possibilites for a bord size are exahusted the size
 * of the board is increased. If the board is longer than 16 * 16 16 bit int
 * a failure is returned. Otherwise, the size of the smallest square is 
 * returned. 
 */
int		solve(t_tetris *block, const int num_of_blocks,
		uint16_t *bit_map)
{
	int	size;

	size = 2;
	while ((size * size) < (num_of_blocks * 4))
		size++;
	size--; 
	while (++size <= 16 && !solve_bit_map(block, size, bit_map)) //keeps trying squares until it gets it or exceed 16 limit
	{
		ft_bzero(bit_map, sizeof(uint16_t) * 16);//clears the map every time it goes wrong
	}
	if (size >= 17)
		return (0);
	return (size);
}

int		print_solve(t_tetris *first, int num_of_blocks)
{
	uint16_t	*bit_map;
	int			size;

	size = 0;
	bit_map = (uint16_t *)malloc(sizeof(uint16_t) * 16);//creates empty map;
	ft_bzero(bit_map, sizeof(uint16_t) * 16); 
	if (!(num_of_blocks)) //tests wrong input
	{
		ft_putendl("error");
		return (1);
	}
	if (!(size = solve(first, num_of_blocks, bit_map)))
	{
		ft_putendl("error");
		return (1);
	}
	print_map(first, num_of_blocks, size);
	free(bit_map);
	while (first!=NULL)
	{
		free(first);
		first = first->next;
	}
	return (0);
}
