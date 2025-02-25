/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:29:25 by danielm3          #+#    #+#             */
/*   Updated: 2025/02/25 19:14:36 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	int				i;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*joined;
	size_t	i;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	joined = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		joined[i] = s1[i];
		i++;
	}
	while (i < s1len + s2len)
	{
		joined[i] = s2[i - s1len];
		i++;
	}
	joined[s1len + s2len] = '\0';
	return (joined);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	sublen;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(1);
		*substr = '\0';
		return (substr);
	}
	sublen = ft_strlen(s) - start;
	if (sublen > len)
		sublen = len;
	substr = (char *)malloc((sublen + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < sublen)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[sublen] = '\0';
	return (substr);
}
