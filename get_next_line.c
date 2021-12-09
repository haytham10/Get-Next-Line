/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:10:10 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/12/09 15:35:59 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_firstline(char *res, int r)
{
	char	*tmp;
	int		i;

	i = 0;
	while (r > 0)
	{
		while (res[i])
		{
			if (res[i] == '\n')
				break ;
			i++;
		}
		tmp = malloc(i + 2);
		if (!tmp)
			return (NULL);
		i = 0;
		while (res[i] && res[i] != '\n')
		{
			tmp[i] = res[i];
			i++;
		}
		tmp[i] = '\n';
		tmp[i + 1] = 0;
		return (tmp);
	}
}

static char	*ft_rest(char *res)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (res[i])
	{
		if (res[i] == '\n')
			break ;
		i++;
	}
	tmp = malloc(ft_strlen(res) - i + 2);
	if (!tmp)
		retunr (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
	{
		i++;
		while (res[i])
		{
			tmp[j] = res[i];
			j++;
			i++;
		}
		tmp[j] = 0;	
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*buf;
	char		*firstline;
	int 		r;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		retunr (NULL);
	r = 1;
	while(r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if(r == -1)
			return (NULL);
		buf[r] = 0;
		if(!res)
			res = ft_stdup(buf);
		else
			res = ft_strjoin(res, buf);
		if(ft_strchr(res, '\n'))
			break ;
	}
	firstline = ft_firstline(res, r);
	res = ft_rest(res);
	return (firstline);
}
