/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <jcampagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:58:44 by jcampagn          #+#    #+#             */
/*   Updated: 2022/02/19 16:53:00 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**malloc_map(int fd, t_stuff *stuff)
{
	char	**map;
	char	*line;

	map = NULL;
	errno = 0;
	line = get_next_line(fd);
	if (errno)
		error();
	if (!line || line[0] == 0)
		free(line);
	stuff->line_len = ft_strlen(line);
	stuff->line_len -= (stuff->line_len && line[stuff->line_len - 1] == '\n');
	while (line)
	{
		free(line);
		(stuff->line_count)++;
		line = get_next_line(fd);
	}
	map = (char **)malloc(sizeof(char *) *(stuff->line_count + 1));
	if (!map)
	{
		perror("Error!\n");
		exit(1);
	}
	return (map);
}

void	get_map(int fd, char **map, t_stuff *stuff)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		map[i] = str;
		len = ft_strlen(map[i]);
		if (len && map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		str = get_next_line(fd);
		if (!map[i])
			map_error_exit(map, i, "Error : gnl failed\n");
		i++;
	}
	map[i] = NULL;
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
	{
		write(2, "Error : Incorrect number of arguments\n", 37);
		exit(1);
	}
	ft_check_file(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error();
	map = malloc_map(fd, &stuff);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error();
	get_map(fd, map, &stuff);
	display_map(map, stuff);
	free_map(map);
	close(fd);
	return (0);
}
