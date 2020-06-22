/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 15:12:19 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/05/27 15:41:54 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_line(t_data *data, int x)
{
	set_texture_variables(data);
	draw_ceiling(data, x);
	draw_wall(data, x);
	draw_floor(data, x);
}

void		draw_vertical_line(t_data *data, int x)
{
	data->draw.line_height = (int)(data->file.res.y / data->ray.perp_wall_dist);
	data->draw.start = (-data->draw.line_height / 2) + (data->file.res.y / 2);
	if (data->draw.start < 0)
		data->draw.start = 0;
	data->draw.end = (data->draw.line_height / 2) + (data->file.res.y / 2);
	if (data->draw.end >= data->file.res.y)
		data->draw.end = data->file.res.y - 1;
	draw_line(data, x);
}
