/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:19:28 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/26 17:15:29 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_len(char *filename)
{
	char	c;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, &c, 1))
	{
		i++;
	}
	close(fd);
	return (i);
}

int		end_of_block(char *file_content, int *i)
{
	while(file_content[*i] != '\n' && (file_content[*i + 1] != '\n' || file_content[*i] != '\0'))
		*i += 1;
	if (file_content[*i + 1] == '\0')
		return (0);
	else
		return (1);
}

int		check_nearby_hashed(char *file_content, int i)
{
	if (i < 18)
	{
		if (file_content[i + 1] == '#')
			return (1);
		if (i < 14)
			if (file_content[i + 5] == '#')
				return (1);
	}
	if (i > 0)
	{
		if (file_content[i - 1] == '#')
			return (1);
		if (i > 4)
			if (file_content[i - 5] == '#')
				return(1);
	}
	return (0);
}

/*helper function to check_dimensions*/
int		conditions_dimensions(char *file_cont, int *width, int *line, int i)
{
	if (file_cont[i] == '\n')
	{
		if ((*width != 5 && *width != 1) || *line > 4)
			return (1);
		if (file_cont[i + 1] == '\n' || file_cont[i + 1] == '\0')
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
