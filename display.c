/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <jcampagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:42:31 by vess              #+#    #+#             */
/*   Updated: 2022/02/19 16:24:58 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_txt(t_data *mlx, t_img *txt, char *path)
{
	txt->img = mlx_xpm_file_to_image(mlx->mlx, path, &txt->h, &txt->w);
	if (!txt->img)
		return (1);
	return (0);
}

int	get_txt(t_data *mlx)
{
	mlx->txt.floor.img = NULL;
	mlx->txt.wall.img = NULL;
	mlx->txt.player.img = NULL;
	mlx->txt.collect.img = NULL;
	mlx->txt.exit.img = NULL;
	return (init_txt(mlx, &mlx->txt.floor, FLOOR)
		|| init_txt(mlx, &mlx->txt.wall, WALL)
		|| init_txt(mlx, &mlx->txt.player, PLAYER)
		|| init_txt(mlx, &mlx->txt.collect, COLLECT)
		|| init_txt(mlx, &mlx->txt.exit, EXIT));
}

void	write_txt(char c, const t_data *mlx, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->txt.wall.img,
			(mlx->txt.wall.w * j), (mlx->txt.wall.h * i));
	else if (c == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->txt.floor.img,
			(mlx->txt.floor.w * j), (mlx->txt.floor.h * i));
	else if (c == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->txt.player.img,
			(mlx->txt.player.w * j), (mlx->txt.player.h * i));
	else if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->txt.exit.img,
			(mlx->txt.exit.w * j), (mlx->txt.exit.h * i));
	else if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->txt.collect.img,
			(mlx->txt.collect.w * j), (mlx->txt.collect.h * i));
}

void	put_txt(char **map, t_data mlx, t_stuff stuff)
{
	int	i;
	int	j;

	i = 0;
	while (i < stuff.line_count)
	{
		j = 0;
		while (j < stuff.line_len)
		{
			write_txt(map[i][j], &mlx, i, j);
			j++;
		}
		i++;
	}
}

void	display_map(char **map, t_stuff stuff)
{
	t_data	mlx;
	t_combo	combo;

	combo.map = map;
	combo.stuff = &stuff;
	combo.count = 0;
	combo.mlx = &mlx;
	mlx.mlx = mlx_init();
	mlx.win = NULL;
	if (mlx.mlx == NULL)
	{
		free_map(map);
		exit(1);
	}
	if (get_txt(&mlx))
		free_mlx(&mlx, map);
	mlx.win = mlx_new_window(mlx.mlx, (mlx.txt.floor.w * (stuff.line_len)),
			(mlx.txt.floor.h * stuff.line_count), "So Long !");
	put_txt(map, mlx, stuff);
	mlx_hook(mlx.win, 2, (1L << 0), key_hook, &combo);
	mlx_hook(mlx.win, 17, (1L << 0), ft_close_cross, &combo);
	mlx_loop(mlx.mlx);
}
