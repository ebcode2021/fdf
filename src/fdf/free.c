/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:00:35 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 14:48:38 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_data(char **dataset)
{
	int	idx;

	idx = 0;
	while (dataset[idx])
	{
		free(dataset[idx]);
		idx++;
	}
	free(dataset);
}

void	free_map(t_pixel **map, int m_row)
{
	int	row;

	row = 0;
	while (row < m_row)
	{
		free(map[row]);
		row++;
	}
	free(map);
}
