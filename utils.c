/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:19:55 by vess              #+#    #+#             */
/*   Updated: 2022/02/17 17:22:31 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
