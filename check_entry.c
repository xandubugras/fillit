/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:48:13 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/27 14:20:42 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/* tests to be made:
 * if there are only dots and #; done
 * if there are more than 4 characters every line; done
 * if there are more than 4 lines between each empty line; done
 * if there are # different than 4
 * if there are non-touching # */
int		check_entry(int fd)
{
	char	reader[22];
	int		count;

	reader[21] = '\0';
	while ((count = read(fd, reader, 21)) >= 20)
	{
		if (check_characters_and_num(reader))
		{
			printf("WRONG CHARACTERS\n");
			return (1);
		}
		if (count == 21 && reader[20] != '\n')
		{
			printf("WRONG DIMENSIONS\n");
			return (1);
		}
		if (hashtag_position(reader))
		{
			printf("HASHTAGS NOT TOUCHING\n");
			return (1);
		}
	}
	return (0);
}

/*checks if there are only dots and # (+ \n and \0) in the file*/
int		check_characters_and_num(char reader[22])
{
	int		i;
	int		blocks;

	i = 0;
	blocks = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (reader[i] != '.' && reader[i] != '#')
			{
				ft_putstr("not a . or #\n");
				return (1);
			}
			if (reader[i] == '#' && ++blocks > 4)
			{
				ft_putstr("more than 4 hashtahgs\n");
				return (1);
			}
		}
		else if (reader[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int		hashtag_position(const char str[22])
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (!(block == 6 || block == 8));
}
