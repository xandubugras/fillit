/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_blocks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:22:59 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/27 18:45:43 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

char	**allocate_blocks(char *file_cont, int file_len)
{
	int		i;
	int		j;
	int		k;
	char	**tetraminos;

	tetraminos = (char **)malloc(sizeof(char *) * (file_len / 21) + 1);
	i = 0;
	j = 0;
	k = 0;
	while (i < file_len / 21)
	{
		tetraminos[i] = ft_strnew(20);
		while (j < 20)
		{
			tetraminos[i][j] = file_cont[k];
			j++;
			k++;
		}
		tetraminos[i][j] = '\0';
		i++;
		k++;
		j = 0;
	}
	tetraminos[file_len / 21] = NULL;
	return (tetraminos);
}

int		check_len(char *filename)
{
	char	c;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, &c, 1))
		i++;
	close(fd);
	return (i);
}

int		get_num_tetraminos(char *fname)
{
	int file_len;

	file_len = check_len(fname);
	return ((file_len + 1) / 21);
}

void	free_tetraminos_str(char **tetraminos)
{
	char **init;

	init = tetraminos;
	while (*tetraminos)
	{
		free(*tetraminos);
		tetraminos++;
	}
	free(init);
}
