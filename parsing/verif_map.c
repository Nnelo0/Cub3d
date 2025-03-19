/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:36:58 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/19 15:13:19 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	verif_caracter(t_cub *cub)
{
	int	i;
	int	j;
	int	type;

	i = 0;
	type = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != '1' && cub->map[i][j] != '0'
				&& cub->map[i][j] != ' ' && cub->map[i][j] != 'N'
				&& cub->map[i][j] != 'S' && cub->map[i][j] != 'E'
				&& cub->map[i][j] != 'W')
			{
				printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: \
%d \033[1;35mand \033[1;34m<x>: %d \033[1;35mnot allowed in map file \
\033[1;33monly [1] [0] [ ] [N] [S] [E] [W] is allowed\n",
					cub->map[i][j], i + 1, j + 1);
				type = -1;
			}
			j++;
		}
		i++;
	}
	return (type);
}

int	verif_wall(t_cub *cub)
{
	int	i;
	int	j;
	int	type;

	i = 0;
	type = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j + 1])
			j++;
		if (cub->map[i][j] != '1')
		{
			printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: \
%d \033[1;35mand \033[1;34m<x>: %d \033[1;35mmust be a [1] \033[1;33m\
<usage>: map must be surround by wall\n",
				cub->map[i][j], i + 1, j + 1);
			type = -1;
		}
		j = 0;
		while (cub->map[i][j] == ' ')
			j++;
		if (cub->map[i][j] != '1')
		{
			printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: \
%d \033[1;35mand \033[1;34m<x>: %d \033[1;35mmust be a [1] \033[1;33m\
map must be surround by wall\n", cub->map[i][j], i + 1, j + 1);
			type = -1;
		}
		i++;
	}
	return (type);
}

int	verif_one_player(t_cub *cub)
{
	int	i;
	int	j;
	int	type;
	int	player;

	i = 0;
	type = 0;
	player = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'W' || cub->map[i][j] == 'E'
				|| cub->map[i][j] == 'S' || cub->map[i][j] == 'N')
			{
				if (player)
				{
					printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: \
%d \033[1;35mand \033[1;34m<x>: %d \033[1;35mone player is allowed in map file \
\033[1;33m<usage>: [N] or [S] or [W] or [E] for according the player to the \
orientation\n", cub->map[i][j], i + 1, j + 1);
					type = -1;
				}
				if (!player)
					cub->player_x = j;
				if (!player)
					cub->player_y = i;
				if (!player && cub->map[i][j] == 'W')
					cub->player = ft_strdup("W");
				if (!player && cub->map[i][j] == 'E')
					cub->player = ft_strdup("E");
				if (!player && cub->map[i][j] == 'S')
					cub->player = ft_strdup("S");
				if (!player && cub->map[i][j] == 'N')
					cub->player = ft_strdup("N");
				player = 1;
			}
			j++;
		}
		i++;
	}
	if (!player)
	{
		printf("\033[1;31mError\n\033[1;35mneed a player in map file \
\033[1;33m<usage>: [N] or [S] or [W] or [E] for according the player \
to the orientation\n");
		type = -1;
	}
	return (type);
}

int	valid_positions(t_cub *cub, int y, int x)
{
	int	type;

	type = 0;
	if (caract(cub->map[y][x + 1]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : \
[0] [1] [N] [S] [W] [E]\n", cub->map[y][x + 1], y + 1, x + 2, cub->map[y][x],
			y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y][x - 1]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d>\033[1;33m<usage>: [0] must be surround by valid caracter \
: [0] [1] [N] [S] [W] [E]\n", cub->map[y][x - 1], y + 1, x, cub->map[y][x],
			y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y + 1][x]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : \
[0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x], y + 2, x + 1, cub->map[y][x],
			y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y - 1][x]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter \
: [0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x], y, x + 1, cub->map[y][x],
			y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y - 1][x - 1]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter \
: [0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x - 1], y, x, cub->map[y][x],
			y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y - 1][x + 1]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : \
[0] [1] [N] [S] [W] [E]\n", cub->map[y - 1][x + 1], y, x + 2, cub->map[y][x],
			y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y + 1][x + 1]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : \
[0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x + 1], y + 2, x + 2,
			cub->map[y][x], y + 1, x + 1);
		type = -1;
	}
	if (caract(cub->map[y + 1][x - 1]))
	{
		printf("\033[1;31mError\n\033[1;35m map is not playable : \
\033[1;36m{%c}\033[1;35m in \033[1;34my:<%d> \033[1;35mand \033[1;34mx<%d> \
\033[1;35mof \033[1;36m{%c} \033[1;35min \033[1;34my:<%d> \033[1;35mand \
\033[1;34mx:<%d> \033[1;33m<usage>: [0] must be surround by valid caracter : \
[0] [1] [N] [S] [W] [E]\n", cub->map[y + 1][x - 1], y + 2, x, cub->map[y][x],
			y + 1, x + 1);
		type = -1;
	}
	return (type);
}

int	verif_is_playable(t_cub *cub)
{
	int	y;
	int	x;
	int	type;

	y = 0;
	type = 0;
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
					type = -1;
			}
			x++;
		}
		y++;
	}
	return (type);
}
