/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:47:19 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/11/23 10:13:47 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *res)
{
	int		read_bytes;
	char	read_buff[BUFF_SIZE + 1];
	int		count;
	size_t	slen;

	slen = 0;
	while ((read_bytes = read(fd, read_buff, BUFF_SIZE)) > 0)
	{
		read_buff[read_bytes] = '\0';
		if (!(res))
		{
			res = malloc(sizeof(char) * (read_bytes + 1));
			if (!res)
				return (NULL);
			ft_bzero(res, read_bytes + 1);
			ft_memcpy(res, read_buff, read_bytes);
		}
		else
			res = ft_strjoin(res, read_buff);
	}
	slen = ft_strlen(res);
	res[slen] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res;

	if (fd == -1)
		return (0);
	res = read_line(fd, res);
	//free(res);
	return (res);
}

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

int	main(int argc, char *argv[])
{
	int	fd;
	char	*file_name;

	file_name = NULL;
	if (argc == 2)
		file_name = argv[1];
	else
		printf("ERROR:there are more than one file as an input!\n");
	fd = open(file_name, O_RDONLY);
	get_next_line(fd);
	return (0);
}