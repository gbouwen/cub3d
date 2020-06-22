/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_sprite_positions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:32:54 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/03 14:17:26 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*static void	set_dist_to_player(t_data *data)*/
/*{*/

/*}*/

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
//				set_dist_to_player(data);
				i++;
			}
			x++;
		}
		y++;
	}
}
