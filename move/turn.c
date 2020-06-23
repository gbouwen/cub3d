/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turn.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/14 13:31:44 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/23 18:03:00 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	turn_left(t_data *data)
{
	double	rotspeed;
	double	old_dir_vec_x;
	double	old_camera_plane_x;

	rotspeed = 0.03;
	old_dir_vec_x = data->ray.dir_vec.x;
	old_camera_plane_x = data->ray.camera_plane.x;
	data->ray.dir_vec.x = data->ray.dir_vec.x * cos(-rotspeed) -
						data->ray.dir_vec.y * sin(-rotspeed);
	data->ray.dir_vec.y = old_dir_vec_x * sin(-rotspeed) +
						data->ray.dir_vec.y * cos(-rotspeed);
	data->ray.camera_plane.x = data->ray.camera_plane.x * cos(-rotspeed) -
							data->ray.camera_plane.y * sin(-rotspeed);
	data->ray.camera_plane.y = old_camera_plane_x * sin(-rotspeed) +
							data->ray.camera_plane.y * cos(-rotspeed);
}

void	turn_right(t_data *data)
{
	double	rotspeed;
	double	old_dir_vec_x;
	double	old_camera_plane_x;

	rotspeed = 0.03;
	old_dir_vec_x = data->ray.dir_vec.x;
	old_camera_plane_x = data->ray.camera_plane.x;
	data->ray.dir_vec.x = data->ray.dir_vec.x * cos(rotspeed) -
						data->ray.dir_vec.y * sin(rotspeed);
	data->ray.dir_vec.y = old_dir_vec_x * sin(rotspeed) +
						data->ray.dir_vec.y * cos(rotspeed);
	data->ray.camera_plane.x = data->ray.camera_plane.x * cos(rotspeed) -
							data->ray.camera_plane.y * sin(rotspeed);
	data->ray.camera_plane.y = old_camera_plane_x * sin(rotspeed) +
							data->ray.camera_plane.y * cos(rotspeed);
}
