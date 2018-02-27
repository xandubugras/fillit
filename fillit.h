/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:41:02 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/26 18:21:57 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define ENDOFBLOCK file_cont[i] == '\n' && (file_cont[i + 1] == '\n' || file_cont[i + 1] == '\0')
# include <libft.h>
# include <fcntl.h>

int		check_entry(char *fname);

int		check_characters(char *fname);

int		check_len(char *fname);

int		end_of_block(char *file_cont, int *i);

int		check_nearby_hashed(char *file_cont, int i);

int		check_dimensions(char *fname);

int		conditions_dimensions(char *file_cont, int *width, int *line, int i);

int		num_of_hashtags(char *fname);

int		hashtag_position(char *fname, int hashnum, int starter, int block_num);

char	**allocate_blocks(char *fname);

void	print_map(char **tetraminos);

void	free_map(char **tetraminos);

int		get_num_tetraminos(char *fname);

#endif
