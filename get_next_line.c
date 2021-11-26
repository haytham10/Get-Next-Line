/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 07:47:19 by hmokhtar          #+#    #+#             */
/*   Updated: 2021/11/26 16:44:46 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

//char	*get_next_line(int fd)
int	main()
{
	FILE *the_file = fopen("sample.txt", "r");
	if (the_file == NULL)
		return (0);
	int BUFFSIZE = 2;
	char	line[BUFFSIZE];
	while (fgets(line, (sizeof(line) * BUFFSIZE), the_file))
		ft_putstr(line);	
}