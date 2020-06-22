/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_line_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/06 15:30:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/06/22 17:53:27 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	count_elements(char **elements)
{
	int	i;

	i = 0;
	while (elements[i] != NULL)
		i++;
	return (i);
}

void	check_elements(t_data *data, char **elements, int correct_amount)
{
	if (!elements)
	{
		free_texture_paths(data);
		exit_error(MALLOC_FAIL);
	}
	if (count_elements(elements) != correct_amount)
	{
		free_texture_paths(data);
		exit_error(INVALID_ELEMENT_FORMAT);
	}
}

void	free_all(char **elements)
{
	int	i;

	i = count_elements(elements);
	while (i >= 0)
	{
		free(elements[i]);
		i--;
	}
	free(elements);
}
