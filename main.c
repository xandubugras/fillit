/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:41:50 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/27 13:41:03 by adubugra         ###   ########.fr       */
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
	{
		ft_putstr("failed test\n");
		//return (1);
	}
	else
		ft_putstr("passed test\n");
	tetraminos = allocate_blocks(filename);
	print_solve(set_list_blocks(tetraminos), get_num_tetraminos(filename));
	free_map(tetraminos);
	printf("there are %d tetraminos\n", get_num_tetraminos(filename));
	return (0);
}
