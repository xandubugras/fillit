/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 23:53:16 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/27 19:49:08 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_tetris	*set_list_blocks(char **tetraminos)
{
	char		letter;
	t_tetris	*node;
	t_tetris	*tmp;
	t_tetris	*first;

	letter = 'A';
	first = (create_tetris_struct(*tetraminos, letter));
	node = first;
	tetraminos++;
	letter++;
	while (*tetraminos)
	{
		tmp = node;
		node = create_tetris_struct(*tetraminos, letter);
		node->prev = tmp;
		tmp->next = node;
		letter++;
		tetraminos++;
	}
	return (first);
}
