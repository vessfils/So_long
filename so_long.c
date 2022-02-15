/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:58:44 by jcampagn          #+#    #+#             */
/*   Updated: 2022/02/15 23:32:47 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**malloc_map(int fd, t_stuff *stuff)
{
	char	**map;
	char	*line;

	map = NULL;
	line = get_next_line(fd);
	if (!line || line[0] == 0)
	{
		write(1, "Error\n", 6);
		free(line);
	}
	stuff->line_len = ft_strlen(line);
	while (line)
	{
		free(line);
		(stuff->line_count)++;
		line = get_next_line(fd);
	}
	map = malloc((stuff->line_count + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	return (map);
}

void	get_map(int fd, char **map, t_stuff *stuff)
{
	int	i;

	i = 0;
	map[i] = get_next_line(fd);
	i++;
	while (i < stuff->line_count)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			write(1, "Error : gnl failed\n", 20);
		if (ft_strlen(map[i]) != (size_t)stuff->line_len)
			write(1, "Error : gnl failed\n", 20);
		i++;
	}
	map[i] = 0;
	parse_file(map, stuff);
	return ;
}

void	init_stuff(t_stuff *stuff)
{
	stuff->line_count = 0;
	stuff->line_len = 0;
	stuff->player = 0;
	stuff->collectible = 0;
	stuff->exit = 0;
	stuff->unknown = 0;
	return ;
}

int	main(int ac, char **av)
{
	int					fd;
	char				**map;
	t_stuff				stuff;


	init_stuff(&stuff);
	if (ac != 2)
		return (write(1, "Error\n", 6));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		write(1, "Error\n", 6);
	map = malloc_map(fd, &stuff);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		write(1, "Error\n", 6);
	get_map(fd, map, &stuff);
	//printmap(map);
	printf("%d\n", check_is_surrounded_by_walls(map, &stuff));
	display_map(map, stuff);
	return (0);
}
