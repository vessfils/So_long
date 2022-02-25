/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <jcampagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:19:55 by vess              #+#    #+#             */
/*   Updated: 2022/02/19 16:26:57 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_cross(t_combo *combo)
{
	free_mlx(combo->mlx, combo->map);
	return (0);
}

void	printmap(char **map)
{
	int	i;

	i = 0;
	while (map [i] != 0)
	{
		printf("%s", map[i]);
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)str + i);
	while (i--)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
	}
	return (0);
}

void	ft_check_file(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (ext == NULL || ft_strcmp(".ber", ext) != 0)
	{
		ft_putstr_fd("Error : invalid file name\n", 2);
		exit(1);
	}
}
