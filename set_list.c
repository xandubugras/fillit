/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 23:37:20 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/26 23:51:10 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_tetris	*set_list_blocks(char **tetraminos)
{
	char letter;
	t_tetris *node;
	t_tetris *tmp;

	letter = 'A';
	node = &(create_tetris_struct(*tetraminos, letter));
	tetraminos++;
	letter++;
	while (*tetraminos)
	{
		tmp = node;
		node = create_tetris_struct(*tetraminos, letter);
		node->last = tmp;
		letter++;
		tetraminos++;
	}
	return (node);
}
