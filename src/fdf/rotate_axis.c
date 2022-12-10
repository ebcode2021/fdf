/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:15:35 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 14:37:24 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_image *image, int x, int y, double theta)
{
	double	prev_y;
	double	prev_z;

	prev_y = image->map[y][x].y;
	prev_z = image->map[y][x].z;
	image->map[y][x].y = prev_y * cos(theta) + prev_z * sin(theta);
	image->map[y][x].z = -prev_y * sin(theta) + prev_z * cos(theta);
}

void	rotate_y(t_image *image, int x, int y, double theta)
{
	double	prev_x;
	double	prev_z;

	prev_x = image->map[y][x].x;
	prev_z = image->map[y][x].z;
	image->map[y][x].x = prev_x * cos(theta) + prev_z * sin(theta);
	image->map[y][x].z = -prev_x * sin(theta) + prev_z * cos(theta);
}

void	rotate_z(t_image *image, int x, int y, double theta)
{
	double	prev_x;
	double	prev_y;

	prev_x = image->map[y][x].x;
	prev_y = image->map[y][x].y;
	image->map[y][x].x = prev_x * cos(theta) - prev_y * sin(theta);
	image->map[y][x].y = prev_x * sin(theta) + prev_y * cos(theta);
}
