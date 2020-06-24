/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 15:01:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/24 12:23:30 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	swap(t_sprite_map *sprites_a, t_sprite_map *sprites_b)
{
	t_sprite_map temp;

	temp = *sprites_a;
	*sprites_a = *sprites_b;
	*sprites_b = temp;
}

void		sort_sprites(t_data *data)
{
	int	i;
	int	x;

	i = 0;
	while (i < (data->amount_of_sprites - 1))
	{
		x = 0;
		while (x < (data->amount_of_sprites - i - 1))
		{
			if (data->sprites[x].dist_to_player <
					data->sprites[x + 1].dist_to_player)
				swap(&data->sprites[x], &data->sprites[x + 1]);
			x++;
		}
		i++;
	}
}
