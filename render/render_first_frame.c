/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_first_frame.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 14:37:48 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/22 13:23:25 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_raycast_variables(t_data *data)
{
	data->ray.player_pos.x = 0.0;
	data->ray.player_pos.y = 0.0;
	data->ray.dir_vec.x = 0.0;
	data->ray.dir_vec.y = 0.0;
	data->ray.camera_plane.x = 0.0;
	data->ray.camera_plane.y = 0.0;
	data->ray.camera_x = 0.0;
	data->ray.ray_dir.x = 0.0;
	data->ray.ray_dir.y = 0.0;
	data->ray.box_map.x = 0;
	data->ray.box_map.y = 0;
	data->ray.side_dist.x = 0.0;
	data->ray.side_dist.y = 0.0;
	data->ray.delta_dist.x = 0.0;
	data->ray.delta_dist.y = 0.0;
	data->ray.perp_wall_dist = 0.0;
	data->ray.step.x = 0;
	data->ray.step.y = 0;
	data->ray.hit = 0;
	data->ray.side = 0;
}

static void	init_move_turn_variables(t_data *data)
{
	data->move.forward = 0;
	data->move.backward = 0;
	data->move.left = 0;
	data->move.right = 0;
	data->turn.left = 0;
	data->turn.right = 0;
}

static void	init_zbuffer(t_data *data)
{
	data->zbuffer = ft_calloc(data->file.res.x, 8);
	if (data->zbuffer == NULL)
		exit_error(MALLOC_FAIL);
}

static void	init_sprites_array(t_data *data)
{
	data->sprites = ft_calloc(data->amount_of_sprites, 16);
	if (data->sprites == NULL)
		exit_error(MALLOC_FAIL);
}

void		render_first_frame(t_data *data)
{
	get_textures_from_files(data);
	get_sprite_from_file(data);
	init_raycast_variables(data);
	init_move_turn_variables(data);
	init_zbuffer(data);
	count_sprites(data);
	init_sprites_array(data);
	get_player_position(data);
	get_direction_vector(data);
	set_camera_plane(data);
	get_sprite_positions(data);
	render_screen(data);
	if (data->file.save_to_bmp == 1)
		screenshot(data);
}
