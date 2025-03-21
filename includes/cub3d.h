/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:03:21 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/21 22:10:37 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "parsing.h"

# define WIDTH 1800
# define HEIGHT 900
# define ROTATE 0.01574533
# define SPEED	0.03

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
	int			keys[65365];
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;
}	t_data;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

int		handle_close(t_data *data);
int		render(t_data *data);
int		update(t_data *data);
int		read_map_tmp(t_data *data);
int		key_release(int keycode, t_data *data);
int		key_press(int keycode, t_data *data);
void	init_keys(t_data *data);
void	cast_rays(t_data *data);
void	turn(t_data *data, int sens);
void	destroy_image(t_data *data);
void	move(t_data *data, int sens);
void	left_right(t_data *data, int sens);
void	put_pixel(t_data *data, int x, int y, int color);
void	init_ray(t_data *data, int x, t_ray *ray);
void	init_step(t_data *data, t_ray *ray);
#endif
