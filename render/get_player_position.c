/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player_position.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/12 15:22:52 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/23 12:45:50 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_player_position(t_data *data)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (data->file.map[y] != NULL)
	{
		x = 0;
		while (data->file.map[y][x] != '\0')
		{
			c = data->file.map[y][x];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				data->ray.player_pos.x = x;
				data->ray.player_pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
