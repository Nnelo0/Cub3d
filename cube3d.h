/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:03:21 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/18 12:40:16 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"

# define WIDTH 1800
# define HEIGHT 900
# define ROTATE 0.0872665

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		**map;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;
}	t_data;

int		handle_close(t_data *data);
int		handle_key(int keycode, t_data *data);
int		read_map(t_data *data);
void	cast_rays(t_data *data);

#endif
