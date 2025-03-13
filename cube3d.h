/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:03:21 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/13 11:10:35 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include "libft/libft/libft.h"
# include "libft/printf/ft_printf.h"
# include <stdbool.h>
# include <math.h>

typedef struct data
{
	void	*mlx;
	void	*window;
	char	**map;
}	t_data;

#endif