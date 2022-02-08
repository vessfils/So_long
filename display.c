/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:42:31 by vess              #+#    #+#             */
/*   Updated: 2022/02/08 23:41:34 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 void	init_txt(t_data *mlx, t_img *txt, char *path)
{
	txt->img = mlx_xpm_file_to_image(mlx->mlx, path, &txt->h, &txt->w);
}

 void	get_txt(t_data *mlx)
{
	init_txt(mlx, &mlx->txt.floor, FLOOR);
	init_txt(mlx, &mlx->txt.wall, WALL);
	init_txt(mlx, &mlx->txt.player, PLAYER);
	init_txt(mlx, &mlx->txt.collect, COLLECT);
	init_txt(mlx, &mlx->txt.exit, EXIT);
}

void	write_txt(char c, t_data mlx, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.wall.img,
			(mlx.txt.wall.w * j), (mlx.txt.wall.h * i));
	else if (c == '0')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.floor.img,
			(mlx.txt.floor.w * j), (mlx.txt.floor.h * i));
	else if (c == 'P')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.player.img,
			(mlx.txt.player.w * j), (mlx.txt.player.h * i));
	else if (c == 'E')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.exit.img,
			(mlx.txt.exit.w * j), (mlx.txt.exit.h * i));
	else if (c == 'C')
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.txt.collect.img,
			(mlx.txt.collect.w * j), (mlx.txt.collect.h * i));
}


void put_txt (char **map, t_data mlx, t_stuff stuff)
{
	int	i;
	int	j;

	i = 0;


	while (i < stuff.line_count)
	{
		j= 0;

		while (j < stuff.line_len)
		{
			write_txt(map[i][j], mlx, i, j);
			j++;
		}
		i++;
	}
}
void	display_map(char **map, t_stuff stuff)
{
	t_data	mlx;
	//t_combo	combo;
	
//	combo.map = map;
//	combo.stuff = &stuff;
//	combo.count = 0;

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
	{
		exit(1);
	}
	get_txt(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, (mlx.txt.floor.w * stuff.line_len),
			(mlx.txt.floor.h * stuff.line_count), "So Long !");
	put_txt(map, mlx, stuff);
	mlx_loop(mlx.mlx);
//	combo.mlx = &mlx;
}
