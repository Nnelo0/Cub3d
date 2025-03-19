/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:49:07 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/19 15:21:19 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	ft_isdigit_s(char *s, char *extra, char *index)
{
	int	i;
	int	type;

	i = 0;
	type = 0;
	while (s[i])
	{
		if (!('0' <= s[i] && '9' >= s[i]))
		{
			printf(RED "ERROR\n\033[1;32m[%c] \033[1;34min \033[1;32m%s \
\033[1;34mof \033[1;32m%s \033[1;33mmust be a digit in 0 and 255\n",
				s[i], extra, index);
			type = -1;
		}
		i++;
	}
	return (type);
}

int	verif_result(int i, char *extra, char *index)
{
	int	type;

	type = 0;
	if (i > 255 || i < 0)
	{
		printf(RED "ERROR\n\033[1;32m[%d] \033[1;34mof \033[1;32m%s \
\033[1;34min \033[1;32m%s \033[1;33mmust be in 0 and 255\n",
			i, extra, index);
		type = -1;
	}
	return (type);
}

int	init_colors(t_cub *cub, char *colors, char *index, int type)
{
	char	**tmp;
	int		r;
	int		g;
	int		b;

	tmp = ft_split(colors, ',');
	if (!tmp || !tmp[0] || !tmp[1] || !tmp[2])
		return (free_array(tmp), print_error(GREEN, "",
				"We need <R> <G> <B> for ", index), -1);
	if (is_digit(tmp, index) == -1)
		return (free_array(tmp), type = -1);
	r = ft_atoi(tmp[0]);
	if (verif_result(r, "<R>", index) == -1)
		type = -1;
	g = ft_atoi(tmp[1]);
	if (verif_result(g, "<G>", index) == -1)
		type = -1;
	b = ft_atoi(tmp[2]);
	if (verif_result(b, "<B>", index) == -1)
		type = -1;
	if (ft_strcmp(index, "{C}") == 0)
		cub->colors_c = ((r << 16) | (g << 8) | b);
	else
		cub->colors_f = ((r << 16) | (g << 8) | b);
	return (free_array(tmp), type);
}

int	verif_c(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->colors_celling)
	{
		print_error(GREEN, "", "Missing <CELLING> colors \033[1;33m<usage>: C <R>, \
<G>, <B>", "");
		return (type = -1);
	}
	if (init_colors(cub, cub->colors_celling, "{C}", 0))
		type = -1;
	return (type);
}

int	verif_f(t_cub *cub)
{
	int	type;

	type = 0;
	if (!cub->colors_floor)
	{
		print_error(GREEN, "", "Missing <FLOOR> colors \033[1;33m<usage>: F <R>, \
<G>, <B>", "");
		return (type = -1);
	}
	if (init_colors(cub, cub->colors_floor, "{F}", 0))
		type = -1;
	return (type);
}
