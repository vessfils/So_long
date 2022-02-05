/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:58:44 by jcampagn          #+#    #+#             */
/*   Updated: 2022/02/05 15:28:05 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Malloc la bonne taille map[x][y]
char **malloc_map(int fd, t_stuff *stuff)
{
	char	**map;
	char	*line;
	
	map = NULL;
	line = get_next_line(fd);
	if (!line || line[0] == 0)
	{
		write(1, "Error\n",6 );
		free(line);
	}
	stuff->line_len = ft_strlen(line);
	while (line)
	{
		free(line);
		(stuff->line_count)++; 
		line = get_next_line(fd);
	}

	map = malloc(stuff->line_count * sizeof(char *));
	if (!map)
		return (NULL);
	return (map);
}
//Mettre la data du fichier dans map avec la bonne memoire
void get_map(int fd, char **map, t_stuff *stuff)
{
	int	i;
	
	i = 0;
	map[i] = get_next_line(fd);
	while (i < stuff->line_count)
	{
		map[i] = get_next_line(fd);
		i++;
	}

}
void	init_stuff(t_stuff *stuff)
{
	stuff->line_count = 0;
	stuff->line_len = 0;
	stuff->player = 0;
	stuff->collectible = 0;
	stuff->exit = 0;
	return ;
}

int	main(void)
{
	char *line = NULL;
	int fd = open("./maps/map.ber", O_RDONLY);
	char	**map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	t_stuff stuff;
	init_stuff(&stuff);
	map = malloc_map(fd, &stuff);
	get_map(fd, map, &stuff);

	return (0);
}
