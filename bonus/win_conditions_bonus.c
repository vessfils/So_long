/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_conditions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:35:11 by vess              #+#    #+#             */
/*   Updated: 2022/02/22 12:20:03 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_left(t_combo *combo)
{
	if (combo->map[combo->stuff->y][combo->stuff->x - 1] != 'E' ||
		(combo->map[combo->stuff->y][combo->stuff->x - 1] == 'E' &&
		combo->stuff->collectible == 0))
		return (1);
	return (0);
}

int	win_right(t_combo *combo)
{
	if (combo->map[combo->stuff->y][combo->stuff->x + 1] != 'E' ||
		(combo->map[combo->stuff->y][combo->stuff->x + 1] == 'E' &&
		combo->stuff->collectible == 0))
		return (1);
	return (0);
}

int	win_up(t_combo *combo)
{
	if (combo->map[combo->stuff->y - 1][combo->stuff->x] != 'E' ||
		(combo->map[combo->stuff->y - 1][combo->stuff->x] == 'E' &&
		combo->stuff->collectible == 0))
		return (1);
	return (0);
}

int	win_down(t_combo *combo)
{
	if (combo->map[combo->stuff->y + 1][combo->stuff->x] != 'E' ||
		(combo->map[combo->stuff->y + 1][combo->stuff->x] == 'E' &&
		combo->stuff->collectible == 0))
		return (1);
	return (0);
}

void	print_mooves(t_combo *combo)
{
	char	*mooves;

	mooves = ft_itoa(combo->count);
	mlx_string_put(combo->mlx->mlx, combo->mlx->win, 0, 15, 0xAB54CB, mooves);
	free(mooves);
}
