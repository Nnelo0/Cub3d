/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:17:09 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/28 10:54:09 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	verif_textures(t_cub *cub, t_data *data)
{
	if (verif_no(cub, data) == -1)
		return (-1);
	if (verif_so(cub, data) == -1)
		return (-1);
	if (verif_ea(cub, data) == -1)
		return (-1);
	if (verif_we(cub, data) == -1)
		return (-1);
	return (0);
}

int	verif_colors(t_cub *cub)
{
	if (verif_c(cub) == -1)
		return (-1);
	if (verif_f(cub) == -1)
		return (-1);
	return (0);
}

int	verif_map(t_cub *cub, t_data *data)
{
	int	type;

	type = 0;
	if (!cub->map || !cub->map[0])
	{
		print_error(GREEN, "", "Missing <MAP> \033[1;33m<usage>: 1 for wall, \
0 for empty spaces, [N][S][E][W] for player", "");
		return (type = -1);
	}
	if (verif_caracter(cub, 0, 0) == -1)
		return (type = -1);
	if (verif_wall(cub, 0, 0) == -1)
		return (type = -1);
	if (verif_one_player(cub, 0, 0, data) == -1)
		return (type = -1);
	if (verif_is_playable(cub) == -1)
		return (free(cub->player), type = -1);
	return (type);
}

int	verif(t_cub *cub, t_data *data)
{
	if (verif_textures(cub, data) == -1)
		return (free_array(cub->map), -1);
	if (verif_colors(cub) == -1)
		return (free_array(cub->map), -1);
	if (verif_map(cub, data) == -1)
		return (free_array(cub->map), -1);
	return (0);
}
