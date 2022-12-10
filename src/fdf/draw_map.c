/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:02:19 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 14:43:42 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_image *img)
{
	int	row;
	int	col;

	row = 0;
	while (row < img->map_row)
	{
		col = 0;
		while (col < img->map_col)
		{
			if (row != img->map_row - 1)
				bresenham(img, img->map[row][col], img->map[row + 1][col]);
			if (col != img->map_col - 1)
				bresenham(img, img->map[row][col], img->map[row][col + 1]);
			col++;
		}
		row++;
	}
}
