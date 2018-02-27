/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:41:50 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/26 20:05:10 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		main(int argc, char **argv)
{
	char *filename;
	char **tetraminos;

	if (argc != 2)
	{
		printf("usage: ./fillit name_of_the_tetrimino_file.txt\n");
		return (0);
	}
	filename  = argv[1];
	if (open(filename, O_RDONLY) == -1)
	{
		printf("file failed to open\n");
		return (0);
	}
	if (check_entry(filename))
		printf("failed test\n");
	else
		printf("passed test\n");
	tetraminos = allocate_blocks(filename);
	print_map(tetraminos);
	print_elem(tetraminos);
	free_map(tetraminos);
	printf("there are %d tetraminos\n", get_num_tetraminos(filename));
	return (0);
}
