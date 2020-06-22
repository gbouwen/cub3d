/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/11 16:33:04 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/22 11:55:06 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	setup_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->file.res.x,
									data->file.res.y, "cub3d");
	data->mlx.img.img = mlx_new_image(data->mlx.mlx, data->file.res.x,
															data->file.res.y);
	data->mlx.img.addr =
	mlx_get_data_addr(data->mlx.img.img, &data->mlx.img.bits_per_pixel,
						&data->mlx.img.line_len, &data->mlx.img.endian);
}

void	close_screen_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->mlx.img.img);
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	exit(0);
}

void	get_correct_resolution(t_data *data)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(data->mlx.mlx, &screen_width, &screen_height);
	if (data->file.res.x > screen_width)
		data->file.res.x = screen_width;
	if (data->file.res.y > screen_height)
		data->file.res.y = screen_height;
}
