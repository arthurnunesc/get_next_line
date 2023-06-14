/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:38:08 by anunes-c          #+#    #+#             */
/*   Updated: 2023/06/14 14:42:03 by anunes-c         ###   ########.fr       */
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

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(str) + 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, str, len);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	malloc_size;

	substr = 0;
	s_len = ft_strlen(s);
	if (len < s_len - start)
		malloc_size = len + 1;
	else
		malloc_size = s_len - start + 1;
	if (start >= s_len)
		return (ft_strdup(""));
	substr = (char *)malloc(malloc_size * sizeof(char));
	if (substr == NULL)
		return (0);
	ft_strlcpy(substr, s + start, malloc_size);
	return (substr);
}
