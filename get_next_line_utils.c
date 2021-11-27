/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:47:14 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/11/27 01:23:42 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c)
		return ((char *)&str[i]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *rem_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!rem_str)
	{
		rem_str = (char *)malloc(1 * sizeof(char));
		rem_str[0] = '\0';
	}
	if (!rem_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(rem_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (rem_str)
		while (rem_str[++i] != '\0')
			str[i] = rem_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(rem_str) + ft_strlen(buff)] = '\0';
	free(rem_str);
	return (str);
}

char	*get_line(char *rem_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!rem_str[i])
		return (NULL);
	while (rem_str[i] && rem_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rem_str[i] && rem_str[i] != '\n')
	{
		str[i] = rem_str[i];
		i++;
	}
	if (rem_str == '\n')
	{
		str[i] = rem_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);			
}

char	*new_line(char *rem_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rem_str[i] && rem_str[i] != '\n')
		i++;
	if (!rem_str[i])
	{
		free(rem_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rem_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rem_str[i])
		str[j++] = rem_str[i++];
	str[j] = '\0';
	free(rem_str);
	return (str);
}