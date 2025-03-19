/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:20:17 by ebroudic          #+#    #+#             */
/*   Updated: 2025/03/19 15:20:30 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	is_digit(char **tmp, char *index)
{
	int	type;

	type = 0;
	if (ft_isdigit_s(tmp[0], "<R>", index) == -1)
		type = -1;
	if (ft_isdigit_s(tmp[1], "<G>", index) == -1)
		type = -1;
	if (ft_isdigit_s(tmp[2], "<B>", index) == -1)
		type = -1;
	return (type);
}
