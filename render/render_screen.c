/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_screen.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 13:18:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/22 17:39:37 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_screen(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->file.res.x)
	{
		cast_ray(data, x);
		draw_vertical_line(data, x);
		data->zbuffer[x] = data->ray.perp_wall_dist;
		x++;
	}
	handle_sprites(data);
	if (data->file.save_to_bmp != 1)
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img.img,
																		0, 0);
}
