/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:37:39 by jcampagn          #+#    #+#             */
/*   Updated: 2022/02/19 12:28:03 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_rectengular(char **map, t_stuff *stuff)
{
	int	i;
//	int	len;

	i = 0;
	//len = 0;
	//len = ft_strlen(map[i]);
	while (map[i] != 0)
	{
		printf("map[%d] = %c\n", i, map[i][19]);
		printf("ft_strlen map[%d]= %zu | stuff->line = %d\n",i , ft_strlen(map[i]), stuff->line_len);
		if (ft_strlen(map[i]) != (size_t)stuff->line_len)
			return (0);
		i++;
	}
	return (1);
}

int	check_bord(char *line, t_stuff *stuff)
{
	int	i;

	i = 0;
	while (i < stuff->line_count)
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_is_surrounded_by_walls(char **map, t_stuff *stuff)
{
	int	i;

	i = 0;
	while (i < (stuff->line_count))
	{
		if (i == 0 || i == ((stuff->line_count) - 1))
		{
			if (!check_bord(map[i], stuff))
				return (0);
		}
		if (map[i][0] != '1' || map[i][stuff->line_len - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_characters(char **map, t_stuff *stuff)
{
	int	i;
	int	j;

	i = 0;
	while (i < (stuff->line_count))
	{
		j = 0;
		while (j < (stuff->line_len) - 1)
		{
			if ((map[i][j]) == 'E')
				stuff->exit++;
			else if (map[i][j] == 'C')
				stuff->collectible++;
			else if (map[i][j] == 'P')
			{
				stuff->player++;
				stuff->x = j;
				stuff->y = i;
			}
			else if ((map[i][j] != '1') && (map[i][j] != '0'))
				(stuff->unknown)++;
			j++;
		}
		i++;
	}
}

void	parse_file(char **map, t_stuff *stuff)
{
	if (map[0][1] == '\0')
		map_error_exit(map, stuff->line_count, "the map is empty!\n");
	if (!check_map_rectengular(map, stuff))
		map_error_exit2(map, stuff->line_count, "the map not a recangular!\n");
	if (!check_is_surrounded_by_walls(map, stuff))
		map_error_exit(map, stuff->line_count, "Not surrounded by walls!\n");
	check_characters(map, stuff);
	if (stuff->player != 1)
		map_error_exit(map, stuff->line_count, "Player not presents!\n");
	if (stuff->exit == 0)
		map_error_exit(map, stuff->line_count, "Exit not presents!\n");
	if (stuff->collectible == 0)
		map_error_exit(map, stuff->line_count, "Collectible not presents!\n");
	if (stuff->unknown > 0)
		map_error_exit(map, stuff->line_count, "Unknown characters!\n");
}
