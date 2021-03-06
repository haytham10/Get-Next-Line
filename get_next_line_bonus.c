/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:11:21 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/13 17:26:56 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*alloc_buff(char *buff)
{
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	return (buff);
}

static char	*alloc_res(char *res, char *buff)
{
	if (!res)
		res = ft_strdup(buff);
	else
		res = ft_strjoin(res, buff);
	return (res);
}

static char	*get_line(char *res, int byt)
{
	char	*new_buff;
	int		i;

	i = 0;
	new_buff = NULL;
	if (byt == 0 && *res == '\0')
		return (free(res), NULL);
	while (res[i] != '\0')
	{
		if (res[i] == '\n')
			break ;
		i++;
	}
	if (res[i] == '\n')
	{
		new_buff = (char *)malloc((i + 2) * sizeof(char));
		if (!new_buff)
			return (NULL);
		ft_memcpy(new_buff, res, i);
		new_buff[i] = '\n';
		new_buff[i + 1] = '\0';
		return (new_buff);
	}
	new_buff = ft_strdup(res);
	return (free(res), res = NULL, new_buff);
}

static char	*get_res(char *str)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[i] == '\n')
	{
		tmp = ft_strdup(str + i + 1);
		free(str);
		str = tmp;
		return (str);
	}
	str = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*res[1024];
	char		*buff;
	char		*line;
	int			byt;

	byt = 1;
	buff = NULL;
	line = NULL;
	buff = alloc_buff(buff);
	if (res[fd] && ft_strchr(res[fd], '\n'))
		byt = 0;
	while (byt > 0)
	{
		byt = read(fd, buff, BUFFER_SIZE);
		if (byt < 0)
			return (free(buff), NULL);
		buff[byt] = '\0';
		res[fd] = alloc_res(res[fd], buff);
		if (ft_strchr(res[fd], '\n'))
			break ;
	}
	free(buff);
	return (line = get_line(res[fd], byt), res[fd] = get_res(res[fd]), line);
}
