/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:50:19 by lelanglo          #+#    #+#             */
/*   Updated: 2025/03/27 14:20:34 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_keys(t_data *data)
{
	int	i;

	i = 0;
	while (i < 65365)
		data->keys[i++] = 0;
}

int	key_press(int keycode, t_data *data)
{
	if (keycode < 65365)
		data->keys[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode < 65365)
		data->keys[keycode] = 0;
	return (0);
}

int	update(t_data *data)
{
	if (data->keys[65307])
		handle_close(data);
	if (data->keys[65363])
		turn(data, 1);
	if (data->keys[65361])
		turn(data, -1);
	if (data->keys['w'])
		move(data, 1);
	if (data->keys['s'])
		move(data, -1);
	if (data->keys['a'])
		left_right(data, -1);
	if (data->keys['d'])
		left_right(data, 1);
	render(data);
	return (0);
}
