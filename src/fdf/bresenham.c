/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:57:43 by eunson            #+#    #+#             */
/*   Updated: 2022/12/09 20:58:18 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham_g1(t_image *img, t_pixel start, t_pixel end)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;

	dx = end.x - start.x;
	dy = end.y - start.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	while (start.y < end.y)
	{
		draw_pixel(img, start.x, start.y++, start.rgb);
		if (d > 0)
		{
			start.x += xi;
			d += 2 * (dx - dy);
		}
		else
			d += 2 * dx;
	}
}

static void	bresenham_l1(t_image *img, t_pixel start, t_pixel end)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;

	dx = end.x - start.x;
	dy = end.y - start.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	while (start.x < end.x)
	{
		draw_pixel(img, start.x++, start.y, start.rgb);
		if (d > 0)
		{
			start.y += yi;
			d += 2 * (dy - dx);
		}
		else
			d += 2 * dy;
	}
}

void	bresenham(t_image *img, t_pixel start, t_pixel end)
{
	if (abs(end.y - start.y) < abs(end.x - start.x))
	{
		if (start.x > end.x)
			bresenham_l1(img, end, start);
		else
			bresenham_l1(img, start, end);
	}
	else
	{
		if (start.y > end.y)
			bresenham_g1(img, end, start);
		else
			bresenham_g1(img, start, end);
	}
}
