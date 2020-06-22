/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 15:08:31 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/05/27 15:09:12 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_color(t_color color)
{
	return ((int)color.red << 16 | (int)color.blue << 8 | (int)color.green);
}
