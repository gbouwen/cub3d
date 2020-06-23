/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_sprite_positions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:32:54 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/23 12:48:52 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		get_sprite_positions(t_data *data)
{
	int	y;
	int	i;
	int	x;

	y = 0;
	i = 0;
	while (data->file.map[y] != NULL)
	{
		x = 0;
		while (data->file.map[y][x] != '\0')
		{
			if (data->file.map[y][x] == '2')
			{
				data->sprites[i].pos.y = y;
				data->sprites[i].pos.x = x;
				i++;
			}
			x++;
		}
		y++;
	}
}
