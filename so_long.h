/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:56:59 by jcampagn          #+#    #+#             */
/*   Updated: 2022/02/15 23:30:13 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "./mlx_linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/* -------------------------------------------------------------------------- */
/*                                     MLX                                    */
/* -------------------------------------------------------------------------- */

# define FLOOR	"images/sand.xpm"
# define WALL	"images/cactus.xpm"
# define PLAYER	"images/dino1.xpm"
# define COLLECT	"images/drop1.xpm"
# define EXIT	"images/puddle.xpm"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		h;
	int		w;
}				t_img;

typedef struct s_txt {
	t_img	floor;	
	t_img	wall;
	t_img	collect;
	t_img	exit;
	t_img	player;
}				t_txt;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_txt	txt;
	int		x;
	int		y;
}				t_data;

/* -------------------------------------------------------------------------- */
/*                                     PARSING                                */
/* -------------------------------------------------------------------------- */

typedef struct s_stuff
{
	int	line_count;
	int	line_len;
	int	player;
	int	collectible;
	int	exit;
	int	unknown;
	int	x;
	int	y;
}				t_stuff;

typedef struct s_combo {
	t_data	*mlx;
	t_stuff	*stuff;
	char	**map;
	int		count;
}				t_combo;



/* -------------------------------------------------------------------------- */
/*                                     GNL                                    */
/* -------------------------------------------------------------------------- */
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2 );
char	*ft_get_line(char *str);
char	*ft_new_left_str(char *str);
char	*get_next_line(int fd);

/* -------------------------------------------------------------------------- */
/*                                     SO_long                                */
/* -------------------------------------------------------------------------- */
void	write_txt(char c, const t_data *mlx, int i, int j);
void	put_txt(char **map, t_data mlx, t_stuff stuff);
void	display_map(char **map, t_stuff stuff);
void	init_txt(t_data *mlx, t_img *txt, char *path);
void	get_txt(t_data *mlx);
int		key_hook(int key, t_combo *combo);
void	free_mlx(t_data *mlx, char **map, int line_count);
void	free_map(char **map, int line_count);
void	moove_right(t_combo *combo);
void	moove_left(t_combo *combo);
void	moove_up(t_combo *combo);
int		check_map_rectengular(char **map);
void	printmap(char **map);
void	parse_file(char **map, t_stuff *stuff);
void	check_characters(char **map, t_stuff *stuff);
int		check_bord(char *line);
int		check_is_surrounded_by_walls(char **map, t_stuff *stuff);

#endif
