/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:47:14 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/10 22:35:41 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*s1;
	unsigned const char	*s2;

	i = 0;
	s1 = dest;
	s2 = src;
	if (!dest && !src)
		return (NULL);
	while (n--)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(ft_strlen((char *)s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		max_len;
	char	*s;
	size_t	len1;
	size_t	len2;

	if (!s1)
		return ((char *)s2);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	max_len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(max_len + 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, len1);
	ft_memcpy(s + len1, s2, len2);
	s[max_len] = '\0';
	free((char *)s1);
	return (s);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
