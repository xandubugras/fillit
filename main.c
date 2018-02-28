/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:41:50 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/27 16:00:27 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		main(int argc, char **argv)
{
	char	*filecontent;
	char	**tetraminos;
	int		filesize;

	if (argc != 2)
	{
		printf("usage: ./fillit name_of_the_tetrimino_file.txt\n");
		return (1);
	}

	if (open(argv[1], O_RDONLY) == -1)
	{
		printf("file failed to open\n");
		return (1);
	}
	if (check_entry(open(argv[1], O_RDONLY)))
		return (1);
	filesize = get_num_tetraminos(argv[1]) * 21;
	if (filesize > 26 * 21)
		return (1);
	filecontent = malloc(sizeof(char) * filesize);
	read(open(argv[1], O_RDONLY), filecontent, filesize);
	tetraminos = allocate_blocks(filecontent, filesize);
	print_solve(set_list_blocks(tetraminos), filesize / 21);
	free_tetraminos_str(tetraminos);
	free(filecontent);
	return (0);
}
