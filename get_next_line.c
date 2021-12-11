/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:26:47 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/11 23:19:37 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*alloc_buffer(char *buffer)
{
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}

static char	*alloc_rest(char *rest, char *buffer)
{
	if (!rest)
			rest = ft_strdup(buffer);
	else
			rest = ft_strjoin(rest, buffer);
	return (rest);
}

static char	*get_line(char *rest, int byt)
{
	char	*new_buff;
	int		i;

	i = 0;
	new_buff = NULL;
	if (byt == 0 && *rest == '\0')
		return (free(rest), NULL);
	while (rest[i] != '\0')
	{
		if (rest[i] == '\n')
			break ;
		i++;
	}
	if (rest[i] == '\n')
	{
		new_buff = malloc((i + 2) * sizeof(char));
		if (!new_buff)
			return (NULL);
		ft_memcpy(new_buff, rest, i);
		new_buff[i] = '\n';
		new_buff[i + 1] = '\0';
		return (new_buff);
	}
	new_buff = ft_strdup(rest);
	return (free(rest), rest = NULL, new_buff);
}

static char	*get_rest(char *rest)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (rest[i] != '\0')
	{
		if (rest[i] == '\n')
			break ;
		i++;
	}
	if (rest[i] == '\n')
	{
		tmp = ft_strdup(rest + i + 1);
		free(rest);
		rest = tmp;
		return (rest);
	}
	rest = NULL;
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*buffer;
	char		*line;
	int			byt;

	byt = 1;
	line = NULL;
	buffer = NULL;
	buffer = alloc_buffer(buffer);
	if (rest && ft_strchr(rest, '\n'))
		byt = 0;
	while (byt > 0)
	{
		byt = read(fd, buffer, BUFFER_SIZE);
		if (byt < 0)
			return (free(buffer), NULL);
		buffer[byt] = '\0';
		rest = alloc_rest(rest, buffer);
		if (ft_strchr(rest, '\n'))
			break ;
	}
	free(buffer);
	return (line = get_line(rest, byt), rest = get_rest(rest), line);

}