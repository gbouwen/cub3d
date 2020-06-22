/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_camera_plane.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 15:27:30 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/05/19 15:03:46 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_camera_plane(t_data *data)
{
	char	c;

	c =
	data->file.map[(int)data->ray.player_pos.y][(int)data->ray.player_pos.x];
	if (c == 'N')
	{
		data->ray.camera_plane.x = 0.66;
		data->ray.camera_plane.y = 0.0;
	}
	if (c == 'S')
	{
		data->ray.camera_plane.x = -0.66;
		data->ray.camera_plane.y = 0.0;
	}
	if (c == 'E')
	{
		data->ray.camera_plane.x = 0.0;
		data->ray.camera_plane.y = 0.66;
	}
	if (c == 'W')
	{
		data->ray.camera_plane.x = 0.0;
		data->ray.camera_plane.y = -0.66;
	}
}
