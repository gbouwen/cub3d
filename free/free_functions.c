/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/17 13:43:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/17 14:56:46 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_textures(t_data *data)
{
	if (data->file.north_ptt != NULL)
		free(data->file.north_ptt);
	if (data->file.south_ptt != NULL)
		free(data->file.south_ptt);
	if (data->file.west_ptt != NULL)
		free(data->file.west_ptt);
	if (data->file.east_ptt != NULL)
		free(data->file.east_ptt);
	if (data->file.sprite_ptt != NULL)
		free(data->file.sprite_ptt);
}
