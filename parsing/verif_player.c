/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:19:41 by nnelo             #+#    #+#             */
/*   Updated: 2025/03/28 10:53:52 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	verif_player(t_cub *cub, int i, int j, t_data *data)
{
	if (cub->player)
	{
		printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: \
%d \033[1;35mand \033[1;34m<x>: %d \033[1;35mone player is allowed in map file \
\033[1;33m<usage>: [N] or [S] or [W] or [E] for according the player to the \
orientation\n", cub->map[i][j], i + 1, j + 1);
		free(cub->player);
		return (-1);
	}
	data->player.x = j + 0.5;
	data->player.y = i + 0.5;
	if (cub->map[i][j] == 'W')
		cub->player = ft_strdup("W");
	if (cub->map[i][j] == 'E')
		cub->player = ft_strdup("E");
	if (cub->map[i][j] == 'S')
		cub->player = ft_strdup("S");
	if (cub->map[i][j] == 'N')
		cub->player = ft_strdup("N");
	cub->map[i][j] = '0';
	return (0);
}

int	verif_one_player(t_cub *cub, int i, int j, t_data *data)
{
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'W' || cub->map[i][j] == 'E'
				|| cub->map[i][j] == 'S' || cub->map[i][j] == 'N')
			{
				if (verif_player(cub, i, j, data) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	if (!cub->player)
	{
		printf("\033[1;31mError\n\033[1;35mWe need a player in map file \
\033[1;33m<usage>: [N] or [S] or [W] or [E] for according the player \
to the orientation\n");
		return (-1);
	}
	return (0);
}
