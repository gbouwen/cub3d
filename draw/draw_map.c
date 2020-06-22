/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_floor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 16:36:15 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/05/27 15:41:31 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ceiling(t_data *data, int x)
{
	int	y;
	int	ceiling_color;

	y = 0;
	ceiling_color = get_color(data->file.ceiling_color);
	while (y < data->draw.start)
	{
		my_mlx_pixel_put(&data->mlx.img, x, y, ceiling_color);
		y++;
	}
}

void	draw_wall(t_data *data, int x)
{
	int	y;

	y = data->draw.start;
	while (y < data->draw.end)
	{
		if (data->ray.side == 1 && data->ray.ray_dir.y > 0)
			draw_south_texture_pixel(data, x, y);
		if (data->ray.side == 1 && data->ray.ray_dir.y < 0)
			draw_north_texture_pixel(data, x, y);
		if (data->ray.side == 0 && data->ray.ray_dir.x < 0)
			draw_west_texture_pixel(data, x, y);
		if (data->ray.side == 0 && data->ray.ray_dir.x > 0)
			draw_east_texture_pixel(data, x, y);
		y++;
	}
}

void	draw_floor(t_data *data, int x)
{
	int	y;
	int	floor_color;

	y = data->draw.end;
	floor_color = get_color(data->file.floor_color);
	while (y < data->file.res.y)
	{
		my_mlx_pixel_put(&data->mlx.img, x, y, floor_color);
		y++;
	}
}
