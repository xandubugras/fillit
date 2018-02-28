/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:41:50 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/27 19:48:01 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		ret_err(char *str)
{
	ft_putstr(str);
	return (1);
}

int		print_solve(t_tetris *first, int num_of_blocks)
{
	uint16_t	*bit_map;
	int			size;

	size = 0;
	bit_map = (uint16_t *)malloc(sizeof(uint16_t) * 16);
	ft_bzero(bit_map, sizeof(uint16_t) * 16);
	if (!(num_of_blocks))
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
	while (first != NULL)
	{
		free(first);
		first = first->next;
	}
	return (0);
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
