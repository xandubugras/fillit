/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:48:13 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/26 18:08:46 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/* tests to be made:
 * if there are only dots and #; done
 * if there are more than 4 characters every line; done
 * if there are more than 4 lines between each empty line; done
 * if there are # different than 4
 * if there are non-touching # */
int		check_entry(char *fname)
{
	if (check_characters(fname))
	{
		printf("WRONG CHARACTERS\n");
		return (1);
	}
	if (check_dimensions(fname))
	{
		printf("WRONG DIMENSIONS\n");
		return (1);
	}
	if (num_of_hashtags(fname))
	{
		printf("WRONG NUM OF HASHTAGS\n");
		return (1);
	}
	if (hashtag_position(fname, 0, 0, 0))
	{
		printf("HASHTAGS NOT TOUCHING\n");
		return (1);
	}
	return (0);
}

/*checks if there are only dots and # (+ \n and \0) in the file*/
int		check_characters(char *fname)
{
	int		i;
	int		file_len;
	char	*file_cont;
	int		fd;

	file_len = check_len(fname);
	file_cont = (char *)malloc(sizeof(char) * (file_len + 1));
	fd = open(fname, O_RDONLY);
	read(fd, file_cont, file_len);
	i = 0;
	while (i < file_len)
	{
		if (file_cont[i] != '.' && file_cont[i] != '#' && file_cont[i] != '\n')
		{
			return (1);
		}
		else
			i++;
	}
	return (0);
}

/*checks if there are 4 lines with 4 char*/
int		check_dimensions(char *fname)
{
	int		i;
	int		file_len;
	char	*file_cont;
	int		line;
	int		width;

	file_len = check_len(fname);
	file_cont = (char *)malloc(sizeof(char) * (file_len + 1));
	file_cont[file_len] = '\0';
	read(open(fname, O_RDONLY), file_cont, file_len);
	line = 1;
	width = 1;
	i = 0;
	while (i <= file_len)
	{
		if (conditions_dimensions(file_cont, &width, &line, i))
			return (1);
		i++;
	}
	return (0);
}

int		num_of_hashtags(char *fname)
{
	int		i;
	int		file_len;
	char	*file_cont;
	int		hashnum;

	file_len = check_len(fname);
	file_cont = (char *)malloc(sizeof(char) * (file_len + 1));
	file_cont[file_len] = '\0';
	read(open(fname, O_RDONLY), file_cont, file_len);
	i = -1;
	hashnum = 0;
	while (++i < file_len)
	{
		if (file_cont[i] == '#')
			hashnum++;
		if (ENDOFBLOCK)
		{
			if (hashnum != 4)
				return (1);
			else
				hashnum = 0;
		}
	}
	return (0);
}

int		hashtag_position(char *fname, int hashnum, int starter, int block_num)
{
	int		i;
	int		file_len;
	char	*file_cont;

	file_len = check_len(fname);
	file_cont = (char *)malloc(sizeof(char) * (file_len + 1));
	file_cont[file_len] = '\0';
	read(open(fname, O_RDONLY), file_cont, file_len);
	file_cont += block_num * 21;
	i = starter;
	if (hashnum == 4)
	{
		if (end_of_block(file_cont, &i))
		{
			return (hashtag_position(fname, 0, 0, block_num + 1));
		}
		else
			return (0);
	}
	while (file_cont[i] != '#')
		i++;
	if (check_nearby_hashed(file_cont, i))
		return (hashtag_position(fname, hashnum + 1, i + 1, block_num));
	return (1);
}
