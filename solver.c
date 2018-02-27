/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:54:15 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/26 20:12:54 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	print_bin(uint64_t n)
{
	if (n > 1)
	{
		print_bin(n / 2);
	}
	printf("%llu", n%2);
}
void	print_elem(char **tetraminos)
{
	t_tetris elem;
	elem = create_tetris_struct(tetraminos[0], 'A');
	printf("The height is %d\n", elem.height);
	printf("The width is %d\n", elem.width);
	printf("the binary representation is:");
	print_bin(elem.bit_rep);
	printf("\n");
	printf("The letter is %c\n", elem.letter);
}
