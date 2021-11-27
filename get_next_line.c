/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:47:19 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/11/27 01:06:16 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *rem_str)
{
	char	*buff;
	int		byt;

	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (NULL);
	byt = 1;
	while (!ft_strchr(rem_str, '\n') && byt != 0)
	{
		byt = read(fd, buff, BUFF_SIZE);
		if (byt == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byt] = '\0';
		rem_str = ft_strjoin(rem_str, buff);
	}
	free(buff);
	return (rem_str);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*rem_str;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (0);
	rem_str = read_line(fd, rem_str);
	if (!rem_str)
		return (NULL);
	line = get_line(rem_str);
	rem_str = new_line(rem_str);
	return (line);
}