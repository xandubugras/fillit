/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_blocks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:22:59 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/26 18:22:11 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

char		**allocate_blocks(char *fname)
{
	int		i;
	int		j;
	int		k;
	int		file_len;
	char	*file_cont;
	char	**tetraminos;

	file_len = check_len(fname);
	file_cont = (char *)malloc(sizeof(char) * (file_len + 1));
	file_cont[file_len] = '\0';
	read(open(fname, O_RDONLY), file_cont, file_len);
	tetraminos = malloc(sizeof(char *) * ((file_len + 1) / 21 + 1));
	tetraminos[(file_len + 1) / 21] = NULL;
	tetraminos[0] = malloc(sizeof(char) * 21);
	i = 0;
	j = 0;
	k = 0;
	while (file_cont[i])
	{
		if (ENDOFBLOCK)
		{
			if (file_cont[i + 1] == '\0')
			{
				tetraminos[j + 1] = 0;
				break;
			}
			tetraminos[j][k] = '\0';
			i++;
			k = 0;
			j++;
			tetraminos[j] = malloc(sizeof(char) * 21);
		}
		tetraminos[j][k] = file_cont[i];
		k++;
		i++;
	}
	return (tetraminos);
}

int			get_num_tetraminos(char *fname)
{
	int file_len;
	file_len = check_len(fname);
	return ((file_len + 1) / 21);
}

void		print_map(char **tetraminos)
{
	int i;

	i = 0;
	while (tetraminos[i])
	{
		printf("%s\n", tetraminos[i]);
		i++;
	}
}

void		free_map(char **tetraminos)
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
