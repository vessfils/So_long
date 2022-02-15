/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:37:39 by jcampagn          #+#    #+#             */
/*   Updated: 2022/02/15 23:41:54 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_rectengular(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i] != 0)
	{
		if (ft_strlen(map[i]) != (size_t)len)
			return (0);
		i++;
	}
	return (1);
}

int	check_bord(char *line)
{
	int	i;

	i = 0;
	while (line[i])
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
			if (!check_bord(map[i]))
				return (0);
		}
		if (map[i][0] != '1' || map[i][(stuff->line_len) - 1] != '1')
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
				stuff->player++;
			else if ((map[i][j] != '1') && (map[i][j] != '0'))
				(stuff->unknown)++;
			j++;
		}
		i++;
	}
}

void	parse_file(char **map, t_stuff *stuff)
{
	if (!check_map_rectengular(map))
		write(2, "Map error: the map is not a recangular!\n", 42);
	if (!check_is_surrounded_by_walls(map, stuff))
		write(2, "Map error: the map is not surrounded by walls!\n", 47);
	check_characters(map, stuff);
	if (stuff->player != 1)
		write(2, "Map error: Player not presents!\n", 42);
	if (stuff->exit == 0)
		write(2, "Map error: Exit not presents!\n", 42);
	if (stuff->collectible == 0)
		write(2, "Map error: Collectible not presents!\n", 42);
	if (stuff->unknown > 1)
		write(2, "Map error:  Unknown characters!\n", 42);
}


