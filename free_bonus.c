/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <jcampagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:56:59 by jcampagn          #+#    #+#             */
/*   Updated: 2022/02/19 16:26:00 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_image(int condt, void *mlx, t_img img)
{
	if (condt)
		mlx_destroy_image(mlx, img.img);
}

void	free_mlx(t_data *mlx, char **map)
{
	if (mlx->mlx)
	{
		free_image(mlx->txt.floor.img != NULL, mlx->mlx, mlx->txt.floor);
		free_image(mlx->txt.wall.img != NULL, mlx->mlx, mlx->txt.wall);
		free_image(mlx->txt.collect.img != NULL,
			mlx->mlx, mlx->txt.collect);
		free_image(mlx->txt.exit.img != NULL, mlx->mlx, mlx->txt.exit);
		free_image(mlx->txt.player.img != NULL, mlx->mlx, mlx->txt.player);
		if (mlx->win)
			mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	free_map(map);
	exit(0);
}
