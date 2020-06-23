/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 12:23:31 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/23 17:58:39 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->move.forward = 1;
	if (keycode == S_KEY)
		data->move.backward = 1;
	if (keycode == A_KEY)
		data->move.left = 1;
	if (keycode == D_KEY)
		data->move.right = 1;
	if (keycode == LEFT_ARROW)
		data->turn.left = 1;
	if (keycode == RIGHT_ARROW)
		data->turn.right = 1;
	if (keycode == ESC)
		close_screen_mlx(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->move.forward = 0;
	if (keycode == S_KEY)
		data->move.backward = 0;
	if (keycode == A_KEY)
		data->move.left = 0;
	if (keycode == D_KEY)
		data->move.right = 0;
	if (keycode == LEFT_ARROW)
		data->turn.left = 0;
	if (keycode == RIGHT_ARROW)
		data->turn.right = 0;
	return (0);
}

int	close_window(t_data *data)
{
	close_screen_mlx(data);
	return (0);
}

int	handle_movement(t_data *data)
{
	data->move_counter = 0;
	if (data->move.forward == 1)
		move_forward(data);
	if (data->move.backward == 1)
		move_backward(data);
	if (data->move.left == 1)
		move_left(data);
	if (data->move.right == 1)
		move_right(data);
	if (data->turn.left == 1)
		turn_left(data);
	if (data->turn.right == 1)
		turn_right(data);
	if (data->move.forward == 1 || data->move.backward == 1 ||
		data->move.left == 1 || data->move.right == 1 ||
		data->turn.left == 1 || data->turn.right == 1)
	{
		data->move_counter++;
		printf("ha\n");
		render_screen(data);
	}
	return (0);
}
