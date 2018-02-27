/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:19:28 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/26 16:41:34 by adubugra         ###   ########.fr       */
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
