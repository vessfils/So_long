/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:56:59 by jcampagn          #+#    #+#             */
/*   Updated: 2022/02/15 22:30:22 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_mlx(t_data *mlx, char **map, int line_count)
{
	if (mlx->mlx)
	{
		mlx_destroy_image(mlx->mlx, mlx->txt.floor.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.wall.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.collect.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.exit.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.player.img);
		mlx_destroy_display(mlx->mlx);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx->mlx);
	}
	free_map(map, line_count);
	exit(0);

}
