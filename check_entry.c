/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:48:13 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/26 16:44:01 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*tests to be made: 
 * if there are only dots and #; done
 * if there are more than 4 characters every line; done
 * if there are more than 4 lines between each empty line; done
 * if there are # different than 4
 * if there are non-touching #
*/

int		check_entry(char *filename)
{
	if (check_characters(filename))
		return (1);
	if (check_dimensions(filename))
		return (1);
	if (num_of_hashtags(filename))
		return (1);
	if (hashtag_position(filename, 0, 0, 0))
		return (1);
	return (0);

}

/*checks if there are only dots and # (+ \n and \0) in the file*/

int		check_characters(char *filename)
{
	int		i;
	int		file_len;
	char	*file_content;
	int		fd;

	file_len = check_len(filename);
	file_content = (char *)malloc(sizeof(char) * (file_len + 1));
	fd = open(filename, O_RDONLY);
	read(fd, file_content, file_len);
	i = 0;
	while (i < file_len)
	{
		if (file_content[i] != '.' && file_content[i] != '#' && file_content[i] != '\n')
		{
			return (1);
		}
		else 
			i++;
	}
	return (0);
}

/*checks if there are any lines with more than 4 characters, and more than 4 lines per block*/

int		check_dimensions(char *filename)
{
	int		i;
	int		file_len;
	char	*file_content;
	int		fd;
	int		line;
	int		width;

	file_len = check_len(filename);
	file_content = (char *)malloc(sizeof(char) * (file_len + 1));
	file_content[file_len] = '\0';
	fd = open(filename, O_RDONLY);
	read(fd, file_content, file_len);
	line = 1;
	width = 1;
	i = 0;
	while (i <= file_len)
	{
		if(conditions_dimensions(file_content, &width, &line, i))
			return (1);
		i++;
	}
	return (0);
}

/*checks if the lines and columns have the exat size of 4 and if empty lines are actualy empty*/

int		conditions_dimensions(char *file_content, int *width, int *line, int i)
{
		if (file_content[i] == '\n')
		{
			if ((*width != 5 && *width != 1) || *line > 4)
				return (1);
			if (file_content[i + 1] == '\n' || file_content[i + 1] == '\0')
			{
				if ((*line) != 4)
					return (1);
				*line = 0;
			}
			else
				(*line)++;
			*width = 0;
		}
		(*width)++;
		return (0);
}

int		num_of_hashtags(char *filename)
{
	int		i;
	int		file_len;
	char	*file_content;
	int		hashnum;

	file_len = check_len(filename);
	file_content = (char *)malloc(sizeof(char) * (file_len + 1));
	file_content[file_len] = '\0';
	read(open(filename, O_RDONLY), file_content, file_len);
	i = -1;
	hashnum = 0;
	while (++i < file_len)
	{
		if (file_content[i] == '#')
			hashnum++;
		if (file_content[i] == '\n' && (file_content[i + 1] == '\n' || file_content[i + 1] == '\0'))
		{
			if (hashnum != 4)
				return (1);
			else
				hashnum = 0;
		}
	}
	return (0);
}

int		hashtag_position(char *filename, int hashnum, int starter, int block_num)
{
	int		i;
	int		file_len;
	char	*file_content;

	file_len = check_len(filename);
	file_content = (char *)malloc(sizeof(char) * (file_len + 1));
	file_content[file_len] = '\0';
	read(open(filename, O_RDONLY), file_content, file_len);
	file_content += block_num * 21;
	i = starter;
	if (hashnum == 4)
	{
		printf("blocknum: %d\n", block_num);
		if (end_of_block(file_content, &i))
		{
			return (hashtag_position(filename, 0, 0, block_num + 1));
		}
		else
			return (0);
	}
	while (file_content[i] != '#')
		i++;
	if (i < 18)
	{
		if (file_content[i + 1] == '#')
		{
			hashnum++;
			return (hashtag_position(filename, hashnum, i + 1, block_num));
		}
		if (i < 14)
			if (file_content[i + 5] == '#')
			{
				hashnum++;
				return (hashtag_position(filename, hashnum, i + 1, block_num));
			}
	}	
	if (i > 0)
	{
		if (file_content[i - 1] == '#')
		{
			hashnum++;
			return (hashtag_position(filename, hashnum, i + 1, block_num));
		}
		if (i > 4)
			if (file_content[i - 5] == '#')
			{
				hashnum++;
				return(hashtag_position(filename, hashnum, i + 1, block_num));
			}
	}
	return (1);
}













