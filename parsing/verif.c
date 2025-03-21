/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:17:09 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/21 18:55:38 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	verif_textures(t_cub *cub)
{
	int	type;

	type = 0;
	if (verif_no(cub) == -1)
		type = -1;
	if (verif_so(cub) == -1)
		type = -1;
	if (verif_ea(cub) == -1)
		type = -1;
	if (verif_we(cub) == -1)
		type = -1;
	return (type);
}

int	verif_colors(t_cub *cub)
{
	int	type;

	type = 0;
	if (verif_c(cub) == -1)
		type = -1;
	if (verif_f(cub) == -1)
		type = -1;
	return (type);
}

int	verif_map(t_cub *cub)
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
	if (verif_one_player(cub, 0, 0, 0) == -1)
		return (type = -1);
	if (verif_is_playable(cub) == -1)
		type = -1;
	return (type);
}

int	verif(t_cub *cub)
{
	int	type;

	type = 0;
	if (verif_textures(cub) == -1)
		type = -1;
	if (verif_colors(cub) == -1)
		type = -1;
	if (verif_map(cub) == -1)
		type = -1;
	return (type);
}
