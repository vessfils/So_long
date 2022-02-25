/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:12:55 by vess              #+#    #+#             */
/*   Updated: 2022/02/22 12:20:13 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_nbrlen(int nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char		*str;
	long int	nbr;
	int			i;

	i = 0;
	str = 0;
	nbr = nb;
	str = (char *)malloc(sizeof(char) * ft_nbrlen(nb) + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
		str[0] = '-';
	if (nbr < 0)
		nbr = -nbr;
	str[ft_nbrlen(nb) - i++] = '\0';
	while (nbr >= 10)
	{
		str[ft_nbrlen(nb) - i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[ft_nbrlen(nb) - i++] = (nbr % 10) + 48;
	return (str);
}
