/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:38:15 by hstein            #+#    #+#             */
/*   Updated: 2023/01/26 19:38:15 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_variables	vars;

	vars.fd = fd;
	vars.line = NULL;
	if (!vars.buff_idx)
	{
		vars.buff_len = read(vars.fd, vars.buffer, BUFFER_SIZE);
		vars.buffer[vars.buff_len] = '\0';
		if (vars.buff_len <= 0)
			return (NULL);
		vars.buff_idx = vars.buffer;
	}
	vars.line = ft_getline(&vars);
	return (vars.line);
}

/*
int	main(void)
{
	char	*next_line;
	int		fd;

	fd = open("test_files/variable_nls.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: opening file\n");
		return (0);
	}
	printf("File open with file descriptor %d\n", fd);
	while ((next_line = get_next_line(fd)))
	{
		printf("%s", next_line);
		free(next_line);
	}

	if (next_line)
	{
		free(next_line);
	}
	close(fd);
	printf("File %d closed\n\n", fd);

	return (0);
}
*/
