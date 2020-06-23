/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/17 13:43:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/23 15:58:04 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_texture_paths(t_data *data)
{
	if (data->file.north_ptt)
		free(data->file.north_ptt);
	if (data->file.south_ptt)
		free(data->file.south_ptt);
	if (data->file.west_ptt)
		free(data->file.west_ptt);
	if (data->file.east_ptt)
		free(data->file.east_ptt);
	if (data->file.sprite_ptt)
		free(data->file.sprite_ptt);
}

void	free_data(t_data *data)
{
	free_texture_paths(data);
	if (data->zbuffer)
		free(data->zbuffer);
	if (data->sprites)
		free(data->sprites);
}
