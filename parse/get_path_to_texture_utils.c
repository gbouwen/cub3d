/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_path_to_texture.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/29 11:15:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/29 11:46:31 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	strdup_filename_in_data(t_data *data, char *filename, int id)
{
	if (id == NORTH)
		data->file.north_ptt = ft_strdup(filename);
	if (id == SOUTH)
		data->file.south_ptt = ft_strdup(filename);
	if (id == WEST)
		data->file.west_ptt = ft_strdup(filename);
	if (id == EAST)
		data->file.east_ptt = ft_strdup(filename);
	if (id == SPRITE)
		data->file.sprite_ptt = ft_strdup(filename);
}

void	filename_with_spaces_in_data(t_data *data, char *line, int id)
{
	int		i;
	int		len;

	i = 2;
	len = 0;
	while (line[i] == ' ')
		i++;
	strdup_filename_in_data(data, line + i, id);
}
