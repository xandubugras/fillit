/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:41:50 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/27 18:44:35 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		ret_err(char *str)
{
	ft_putstr(str);
	return (1);
}

int		main(int argc, char **argv)
{
	char	*filecontent;
	char	c;
	char	**tetraminos;
	int		filesize;

	if (argc != 2)
		return (ret_err("usage: ./fillit name_of_the_tetrimino_file.txt\n"));
	if (read(open(argv[1], O_RDONLY), &c, 1) == 0)
		return (ret_err("error\n"));
	if (open(argv[1], O_RDONLY) == -1)
		return (ret_err("error\n"));
	filesize = get_num_tetraminos(argv[1]) * 21;
	if (check_entry(open(argv[1], O_RDONLY), filesize / 21))
		return (ret_err("error\n"));
	if (filesize > 26 * 21)
		return (ret_err("error\n"));
	filecontent = malloc(sizeof(char) * filesize);
	read(open(argv[1], O_RDONLY), filecontent, filesize);
	tetraminos = allocate_blocks(filecontent, filesize);
	print_solve(set_list_blocks(tetraminos), filesize / 21);
	free_tetraminos_str(tetraminos);
	free(filecontent);
	return (0);
}
