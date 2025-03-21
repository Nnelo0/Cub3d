/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:36:58 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/21 18:55:11 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	verif_caracter(t_cub *cub, int i, int j)
{
	int	type;

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
				return (type = -1);
			}
			j++;
		}
		i++;
	}
	return (type);
}

int	first_line(t_cub *cub, int i, int j)
{
	while (cub->map[0][j])
	{
		while (cub->map[0][j] == ' ')
			j++;
		if (cub->map[0][j] != '1')
		{
			printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: \
%d \033[1;35mand \033[1;34m<x>: %d \033[1;35mmust be a [1] \033[1;33m\
<usage>: map must be surround by wall\n", cub->map[i][j], i + 1, j + 1);
			return (-1);
		}
		j++;
	}
	return (0);
}

int	last_line(t_cub *cub, int i, int j)
{
	while (cub->map[i + 1])
		i++;
	while (cub->map[i][j] == ' ')
		j++;
	while (cub->map[i][j])
	{
		if (cub->map[i][j] != '1')
		{
			printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: \
%d \033[1;35mand \033[1;34m<x>: %d \033[1;35mmust be a [1] \033[1;33m\
<usage>: map must be surround by wall\n", cub->map[i][j], i + 1, j + 1);
			return (-1);
		}
		j++;
	}
	return (0);
}

int	verif_wall(t_cub *cub, int i, int j)
{
	if (first_line(cub, i, j) == -1)
		return (-1);
	if (last_line(cub, i, j == -1))
		return (-1);
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j + 1])
			j++;
		if (cub->map[i][j] != '1')
			return (printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: \
%d \033[1;35mand \033[1;34m<x>: %d \033[1;35mmust be a [1] \033[1;33m\
<usage>: map must be surround by wall\n", cub->map[i][j], i + 1, j + 1), -1);
		j = 0;
		while (cub->map[i][j] == ' ')
			j++;
		if (cub->map[i][j] != '1')
			return (printf("\033[1;31mError\n\033[1;35m{%c} in \033[1;34m<y>: \
%d \033[1;35mand \033[1;34m<x>: %d \033[1;35mmust be a [1] \033[1;33m\
map must be surround by wall\n", cub->map[i][j], i + 1, j + 1), -1);
		i++;
	}
	return (0);
}
