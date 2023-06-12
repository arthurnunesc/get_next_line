/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:37:49 by anunes-c          #+#    #+#             */
/*   Updated: 2023/06/12 19:28:50 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*ret_val;
	char	buffer[BUFFER_SIZE];
	ssize_t	read_ret_val;
	int		has_reached_eoloreof;

	ret_val = "";
	has_reached_eoloreof = 0;
	while (!has_reached_eoloreof)
	{
		read_ret_val = read(fd, buffer, sizeof(buffer));
		if (read_ret_val == -1)
		{
			free(buffer);
			return (0);
		}
		ret_val = ft_strjoin((const char *)ret_val, buffer);
		if (!ret_val)
		{
			free(buffer);
			return (0);
		}
		if (ft_strchr(buffer, '\n'))
		{
			has_reached_eoloreof = 1;
			printf("reached end of line\n");
		}
	}
	return (ret_val);
}

#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		fd = open("file1.txt", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	printf("get_next_line output: %s\n", get_next_line(fd));
	return (0);
}
