/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_sprites.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 14:39:52 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/22 10:50:54 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	translate_sprite_position(t_data *data, int i)
{
	data->sprite_calc.sprite.x =
								data->sprites[i].pos.x - data->ray.player_pos.x;
	data->sprite_calc.sprite.y =
								data->sprites[i].pos.y - data->ray.player_pos.y;
}

static void	transform_sprite_with_inverse_camera_matrix(t_data *data)
{
	double	inv_det;

	inv_det = 1 / (data->ray.camera_plane.x * data->ray.dir_vec.y -
					data->ray.dir_vec.x * data->ray.camera_plane.y);
	data->sprite_calc.transform.x = inv_det *
							(data->ray.dir_vec.y * data->sprite_calc.sprite.x -
							data->ray.dir_vec.x * data->sprite_calc.sprite.y);
	data->sprite_calc.transform.y = inv_det *
					(-data->ray.camera_plane.y * data->sprite_calc.sprite.x +
					data->ray.camera_plane.x * data->sprite_calc.sprite.y);
	data->sprite_calc.sprite_screen_x = (int)(data->file.res.x / 2) *
			(1 + data->sprite_calc.transform.x / data->sprite_calc.transform.y);
}

static void	calc_sprite_height(t_data *data)
{
	data->sprite_calc.sprite_height = fabs((data->file.res.y /
											data->sprite_calc.transform.y));
	data->sprite_calc.draw_start.y =
					-data->sprite_calc.sprite_height / 2 + data->file.res.y / 2;
	if (data->sprite_calc.draw_start.y < 0)
		data->sprite_calc.draw_start.y = 0;
	data->sprite_calc.draw_end.y =
					data->sprite_calc.sprite_height / 2 + data->file.res.y / 2;
	if (data->sprite_calc.draw_end.y >= data->file.res.y)
		data->sprite_calc.draw_end.y = data->file.res.y - 1;
}

static void	calc_sprite_width(t_data *data)
{
	data->sprite_calc.sprite_width = fabs(data->file.res.y /
											data->sprite_calc.transform.y);
	data->sprite_calc.draw_start.x =
		-data->sprite_calc.sprite_width / 2 + data->sprite_calc.sprite_screen_x;
	if (data->sprite_calc.draw_start.x < 0)
		data->sprite_calc.draw_start.x = 0;
	data->sprite_calc.draw_end.x =
		data->sprite_calc.sprite_width / 2 + data->sprite_calc.sprite_screen_x;
	if (data->sprite_calc.draw_end.x >= data->file.res.x)
		data->sprite_calc.draw_end.x = data->file.res.x - 1;
}

void	handle_sprites(t_data *data)
{
	int	i;

	calc_dist_from_sprites_to_player(data);
	sort_sprites(data);
	i = 0;
	while (i < data->amount_of_sprites)
	{
		translate_sprite_position(data, i);
		transform_sprite_with_inverse_camera_matrix(data);
		calc_sprite_height(data);
		calc_sprite_width(data);
		draw_sprite(data);
		i++;
	}
}
