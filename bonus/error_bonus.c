/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <jcampagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:38:22 by vess              #+#    #+#             */
/*   Updated: 2022/02/19 16:55:24 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	perror("Error");
	exit(1);
}

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void	map_error_exit(char **map, int line, char *msg)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(map[i]);
		i++;
	}
	free(map);
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	map_error_exit2(char **map, int line, char *msg)
{
	int	i;

	i = 0;
	while (i <= line)
	{
		free(map[i]);
		++i;
	}
	free(map);
	ft_putstr_fd(msg, 2);
	exit(1);
}
