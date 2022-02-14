/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:56:59 by jcampagn          #+#    #+#             */
/*   Updated: 2022/02/15 00:17:01 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	printmap(char **map)
{
	int	i;

	i	=	0;
	while (map [i] != 0)
	{
		printf("%s", map[i]);
		i++;
	}
}

void	moove_right(t_combo *combo)
{
	if (combo->map[combo->stuff->y][combo->stuff->x + 1] == 'C')
		combo->stuff->collectible++;
	if (combo->map[combo->stuff->y][combo->stuff->x + 1] == 'E')
		free_mlx(combo->mlx, combo->map, combo->stuff->line_count);
	combo->map[combo->stuff->y][combo->stuff->x] = '0';
	combo->map[combo->stuff->y][combo->stuff->x + 1] = 'P';
	combo->stuff->x++;
	put_txt(combo->map, *combo->mlx, *combo->stuff);
}

void	moove_left(t_combo *combo)
{
	if (combo->map[combo->stuff->y][combo->stuff->x - 1] == 'C')
		combo->stuff->collectible++;
	if (combo->map[combo->stuff->y][combo->stuff->x - 1] == 'E')
		free_mlx(combo->mlx, combo->map, combo->stuff->line_count);
	combo->map[combo->stuff->y][combo->stuff->x] = '0';
	combo->map[combo->stuff->y][combo->stuff->x - 1] = 'P';
	combo->stuff->x--;
	put_txt(combo->map, *combo->mlx, *combo->stuff);
}

void	moove_up(t_combo *combo)
{
	if (combo->map[combo->stuff->y - 1][combo->stuff->x] == 'C')
		combo->stuff->collectible++;
	if (combo->map[combo->stuff->y - 1][combo->stuff->x] == 'E')
		free_mlx(combo->mlx, combo->map, combo->stuff->line_count);
	combo->map[combo->stuff->y][combo->stuff->x] = '0';
	combo->map[combo->stuff->y - 1][combo->stuff->x] = 'P';
	combo->stuff->y--;
	put_txt(combo->map, *combo->mlx, *combo->stuff);
}

void	moove_down(t_combo *combo)
{
	if (combo->map[combo->stuff->y + 1][combo->stuff->x] == 'C')
		combo->stuff->collectible++;
	if (combo->map[combo->stuff->y - 1][combo->stuff->x] == 'E')
		free_mlx(combo->mlx, combo->map, combo->stuff->line_count);
	combo->map[combo->stuff->y][combo->stuff->x] = '0';
	combo->map[combo->stuff->y + 1][combo->stuff->x] = 'P';
	combo->stuff->y++;
	put_txt(combo->map, *combo->mlx, *combo->stuff);
	
}

int	key_hook(int key, t_combo *combo)
{
	if (key == 65307)
	{	
		free_mlx(combo->mlx, combo->map, combo->stuff->line_count);
	}
	else if (key == 100
		&& combo->map[combo->stuff->y][combo->stuff->x + 1] != '1')
	{
		moove_right(combo);
	}
	else if (key == 97
		&& combo->map[combo->stuff->y][combo->stuff->x - 1] != '1')
	{
		moove_left(combo);
	}
	else if (key == 119
		&& combo->map[combo->stuff->y - 1][combo->stuff->x] != '1')
	{
		moove_up(combo);
	}
	else if (key == 115
		&& combo->map[combo->stuff->y + 1][combo->stuff->x] != '1')
	{
		moove_down(combo);
	}
	return (0);
}

