/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:32:44 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 16:22:54 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	points_interval(t_image *image, int col, int row)
{
	image->map[row][col].x = col * image->per_distance;
	image->map[row][col].y = row * image->per_distance;
	image->map[row][col].z = \
		image->map[row][col].z_value * image->per_distance * 0.2;
}

void	rotation(t_image *image, int x, int y)
{
	rotate_x(image, x, y, M_PI / 6 * image->x_axis);
	rotate_y(image, x, y, M_PI / 6 * image->y_axis);
	rotate_z(image, x, y, M_PI / 6 * image->z_axis);
}

void	isometric_projection(t_image *image, int col, int row)
{
	int	prev_col;
	int	prev_row;

	prev_col = image->map[row][col].x;
	prev_row = image->map[row][col].y;
	image->map[row][col].x = (prev_col - prev_row) * cos(M_PI / 6);
	image->map[row][col].y = \
		(prev_col + prev_row) * sin(M_PI / 6) - image->map[row][col].z;
}

void	move_to_center(t_image *img)
{
	int	row;
	int	col;
	int	distance_x;
	int	distance_y;

	distance_x = MID_X - (img->map[img->map_row / 2][img->map_col / 2].x);
	distance_y = MID_Y - (img->map[img->map_row / 2][img->map_col / 2].y);
	row = 0;
	while (row < img->map_row)
	{
		col = 0;
		while (col < img->map_col)
		{
			img->map[row][col].x += (distance_x + img->x_move);
			img->map[row][col].y += (distance_y + img->y_move);
			col++;
		}
		row++;
	}
}

void	set_coordinate(t_image *image)
{
	int	col;
	int	row;

	row = 0;
	while (row < image->map_row)
	{
		col = 0;
		while (col < image->map_col)
		{
			points_interval(image, col, row);
			if (image->isomatic)
			{
				rotation(image, col, row);
				isometric_projection(image, col, row);
			}
			col++;
		}
		row++;
	}
	move_to_center(image);
}
