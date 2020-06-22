/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_sprites.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 13:34:19 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/03 13:45:59 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	count_sprites(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	data->amount_of_sprites = 0;
	while (data->file.map[y] != NULL)
	{
		x = 0;
		while (data->file.map[y][x] != '\0')
		{
			if (data->file.map[y][x] == '2')
				data->amount_of_sprites++;
			x++;
		}
		y++;
	}
}
