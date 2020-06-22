/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_valid_map.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 16:28:49 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/17 16:01:40 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		flood_fill(t_data *data, int x, int y, char **map)
{
	if (map[y][x] == '1' || map[y][x] == 'x')
		return ;
	if (map[y][x] == '0' || map[y][x] == '2' || map[y][x] == 'N' ||
		map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
	{
		map[y][x] = 'x';
		flood_fill(data, x, y + 1, map);
		flood_fill(data, x, y - 1, map);
		flood_fill(data, x + 1, y, map);
		flood_fill(data, x - 1, y, map);
		flood_fill(data, x + 1, y + 1, map);
		flood_fill(data, x + 1, y - 1, map);
		flood_fill(data, x - 1, y + 1, map);
		flood_fill(data, x - 1, y - 1, map);
	}
	else
		exit_data_error(data, INVALID_MAP);
}

static void		check_first_last_row(t_data *data, char **map, int last)
{
	int	x;

	x = 0;
	while (map[0][x] != '\0')
	{
		if (map[0][x] != '1' && map[0][x] != ' ')
			exit_data_error(data, INVALID_MAP);
		x++;
	}
	x = 0;
	while (map[last][x] != '\0')
	{
		if (map[last][x] != '1' && map[last][x] != ' ')
			exit_data_error(data, INVALID_MAP);
		x++;
	}
}

void			check_valid_map(t_data *data)
{
	t_xy_int	player_pos;
	int			map_rows;
	char		**flood_fill_map;

	check_amount_of_players(data);
	player_pos = get_player_pos(data);
	map_rows = get_amount_of_rows(data);
	flood_fill_map = copy_map(map_rows, data);
	check_first_last_row(data, flood_fill_map, map_rows - 1);
	flood_fill(data, player_pos.x, player_pos.y, flood_fill_map);
}