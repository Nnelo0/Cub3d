/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:40:03 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/31 09:04:09 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	perform_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

static void	norm_draw(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player.x
				+ (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player.y
				+ (1 - ray->step_y) / 2) / ray->dir_y;
	if (ray->side == 0)
		ray->wall_x = data->player.y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = data->player.x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x
			* (double)data->textures[what_texture(ray)].width);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		ray->tex_x = data->textures[what_texture(ray)].width - ray->tex_x - 1;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

static void	draw_column(t_data *data, int x, t_ray *ray)
{
	int	y;

	norm_draw(data, ray);
	y = 0;
	while (y < ray->draw_start)
		put_pixel(data, x, y++, data->c);
	ray->step = 0.95 * data->textures[what_texture(ray)].height
		/ ray->line_height;
	ray->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2)
		* ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos
			% (data->textures[what_texture(ray)].height - 1);
		ray->tex_pos += ray->step;
		ray->color = data->textures[what_texture(ray)].data[ray->tex_y
			* data->textures[what_texture(ray)].width + ray->tex_x];
		put_pixel(data, x, y++, ray->color);
	}
	y = ray->draw_end + 1;
	while (y < HEIGHT)
		put_pixel(data, x, y++, data->f);
}

void	cast_rays(t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(data, x, &ray);
		init_step(data, &ray);
		perform_dda(data, &ray);
		draw_column(data, x, &ray);
		x++;
	}
}
