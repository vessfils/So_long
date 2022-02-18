/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:56:59 by jcampagn          #+#    #+#             */
/*   Updated: 2022/02/18 18:30:19 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//void	free_map(char **map, int line_count)
void	free_map(char **map)
{
	int	i;

	i = 0;
	/*
	while (i < line_count)
	{
		free(map[i]);
		i++;
	}
	free(map);
	*/
  while (map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

//void	free_mlx(t_data *mlx, char **map, int line_count)
void	free_mlx(t_data *mlx, char **map)
{
	if (mlx->mlx)
	{
		mlx_destroy_image(mlx->mlx, mlx->txt.floor.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.wall.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.collect.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.exit.img);
		mlx_destroy_image(mlx->mlx, mlx->txt.player.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	//free_map(map, line_count);
	free_map(map);
	exit(0);
}
