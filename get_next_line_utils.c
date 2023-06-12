/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:38:08 by anunes-c          #+#    #+#             */
/*   Updated: 2023/06/12 19:15:59 by anunes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;
	char			*join;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
	if (!join)
		return (0);
	while (i < s1_len)
	{
		join[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc_c;
	unsigned int	i;

	i = 0;
	uc_c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == uc_c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == uc_c)
		return ((char *)&s[i]);
	return (NULL);
}
