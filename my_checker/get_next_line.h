/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:03:12 by hstein            #+#    #+#             */
/*   Updated: 2023/02/07 16:03:12 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <ctype.h>
# include <fcntl.h>
# include "my_checker.h"

typedef struct variables {
	char	buffer[BUFFER_SIZE + 1];
	char	*buff_idx;
	char	*n_idx;
	char	*line;
	int		buff_len;
	int		fd;
}	t_variables;

char	*get_next_line(int fd);
char	*ft_n_idx(char *ptr_buff_idx);
char	*ft_write_new(char **ptr_line, char *ptr_buff_idx);
char	*ft_write_add(char **ptr_line, char **ptr_buff_idx, char *n_idx);
char	*ft_getline(t_variables *ptr_vars);
int		ft_readbuffer(t_variables *ptr_vars);

#endif
