/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:37:49 by anunes-c          #+#    #+#             */
/*   Updated: 2023/06/19 14:56:30 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_fillstash(char *stash, char *buffer)
{
	char	*new_stash;
	char	*clean_buffer;

	clean_buffer = ft_substr(buffer, 0, BUFFER_SIZE);
	if (!clean_buffer)
		return (0);
	if (!stash || stash[0] == '\0')
	{
		new_stash = clean_buffer;
	}
	else
	{
		new_stash = ft_strjoin(stash, clean_buffer);
		free(stash);
		if (!new_stash)
			return (0);
	}
	return (new_stash);
}

static char	*ft_cleanstash(char *stash, ssize_t line_len)
{
	char	*new_stash;
	ssize_t	stash_len;

	stash_len = ft_strlen(stash);
	new_stash = ft_substr(stash, line_len + 1, stash_len - line_len);
	free(stash);
	if (!new_stash)
		return (0);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		buffer[BUFFER_SIZE];
	ssize_t		read_output;
	ssize_t		line_len;
	int			has_reached_eoloreof;

	if (fd < 0)
		return (0);
	// printf("FD: %i\n", fd);
	line = 0;
	has_reached_eoloreof = 0;
	while (!has_reached_eoloreof)
	{
		read_output = read(fd, buffer, BUFFER_SIZE);
		if (read_output == -1)
			return (0);
		printf("BUFFER: %s\n", buffer);
		// printf("READ OUTPUT: %zi\n", read_output);
		if (ft_strchr(buffer, '\n') || read_output < BUFFER_SIZE)
			has_reached_eoloreof = 1;
		printf("INTERMEDIARY STASH BEFORE: %s\n", stash);
		stash = ft_fillstash(stash, buffer);
		if (!stash)
			return (0);
		printf("INTERMEDIARY STASH AFTER: %s\n", stash);
	}
	// printf("FINAL STASH: %s\n", stash);
	line = 0;
	line_len = 0;
	while (stash[line_len] && stash[line_len] != '\n')
		line_len++;
	printf("LINE_LEN: %lu\n", line_len);
	line = ft_substr(stash, 0, line_len);
	stash = ft_cleanstash(stash, line_len);
	if (!stash)
		return (0);
	if (!line)
		return (0);
	printf("LEFTOVER STASH: %s\n", stash);
	return (line);
}

#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		fd = open("file1.txt", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	for (int i = 0; i < 8; i++)
		printf("get_next_line OUTPUT: %s\n\n\n\n", get_next_line(fd));
	return (0);
}
