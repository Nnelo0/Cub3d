/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:34:24 by nnelo             #+#    #+#             */
/*   Updated: 2025/03/28 10:45:04 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	verif_position_utils(t_cub *cub, int y, int x)
{
	if (caract(cub->map[y + 1][x + 1]))
		return (printf("\033[1;31mError\n\033[1;35mmap is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : \
[0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x + 1], y + 2, x + 2,
			cub->map[y][x], y + 1, x + 1), -1);
	if (caract(cub->map[y + 1][x - 1]))
		return (printf("\033[1;31mError\n\033[1;35mmap is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : \
[0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x - 1], y + 2, x, cub->map[y][x],
			y + 1, x + 1), -1);
	return (0);
}

int	verif_position(t_cub *cub, int y, int x)
{
	if (caract(cub->map[y - 1][x]))
		return (printf("\033[1;31mError\n\033[1;35mmap is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter \
: [0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x], y, x + 1, cub->map[y][x],
			y + 1, x + 1), -1);
	if (caract(cub->map[y - 1][x - 1]))
		return (printf("\033[1;31mError\n\033[1;35mmap is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter \
: [0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x - 1], y, x, cub->map[y][x],
			y + 1, x + 1), -1);
	if (caract(cub->map[y - 1][x + 1]))
		return (printf("\033[1;31mError\n\033[1;35mmap is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : \
[0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x + 1], y, x + 2, cub->map[y][x],
			y + 1, x + 1), -1);
	if (verif_position_utils(cub, y, x) == -1)
		return (-1);
	return (0);
}

int	valid_positions(t_cub *cub, int y, int x)
{
	if (caract(cub->map[y][x + 1]))
		return (printf("\033[1;31mError\n\033[1;35mmap is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : \
[0] [1] [N] [S] [W] [E]\n", cub->map[y][x + 1], y + 1, x + 2, cub->map[y][x],
			y + 1, x + 1), -1);
	if (caract(cub->map[y][x - 1]))
		return (printf("\033[1;31mError\n\033[1;35mmap is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d>\033[1;33m<usage>: [0] must be surround by valid caracter \
: [0] [1] [N] [S] [W] [E]\n", cub->map[y][x - 1], y + 1, x, cub->map[y][x],
			y + 1, x + 1), -1);
	if (caract(cub->map[y + 1][x]))
		return (printf("\033[1;31mError\n\033[1;35mmap is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : \
[0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x], y + 2, x + 1, cub->map[y][x],
			y + 1, x + 1), -1);
	if (verif_position(cub, y, x) == -1)
		return (-1);
	return (0);
}

int	verif_is_playable(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '0' || cub->map[y][x] == 'N'
				|| cub->map[y][x] == 'S' || cub->map[y][x] == 'E'
				|| cub->map[y][x] == 'W')
			{
				if (valid_positions(cub, y, x) == -1)
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
