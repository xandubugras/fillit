/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:41:02 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/26 16:40:41 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <libft.h>
# include <fcntl.h>

int		check_entry(char *filename);

int		check_characters(char *filename);

int		check_len(char *filename);

int		end_of_block(char *file_content, int *i);

int		check_dimensions(char *filename);

int		conditions_dimensions(char *file_content, int *width, int *line, int i);

int		num_of_hashtags(char *filename);

int		hashtag_position(char *filename, int hashnum, int starter, int block_num);

#endif
