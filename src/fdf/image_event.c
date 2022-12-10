/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:49:21 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 16:44:35 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_image(int *distance, int keycode)
{
	if (keycode == KEY_PLUS && *distance + 1 < ZOOM_MAX)
		*distance += 1;
	else if (keycode == KEY_MINUS && *distance - 1 > ZOOM_MIN)
		*distance -= 1;
}

void	move_image(t_image *image, int keycode)
{
	if (keycode == KEY_LEFT)
		image->x_move -= 5;
	else if (keycode == KEY_RIGHT)
		image->x_move += 5;
	else if (keycode == KEY_UP)
		image->y_move -= 5;
	else if (keycode == KEY_DOWN)
		image->y_move += 5;
}

void	rotate_image(t_image *image, int keycode)
{
	if (keycode == KEY_A)
		image->x_axis += 0.1;
	else if (keycode == KEY_S)
		image->x_axis -= 0.1;
	else if (keycode == KEY_D)
		image->y_axis += 0.1;
	else if (keycode == KEY_F)
		image->y_axis -= 0.1;
	else if (keycode == KEY_G)
		image->z_axis += 0.1;
	else if (keycode == KEY_H)
		image->z_axis -= 0.1;
}

void	projection_image(t_image *image, int keycode)
{
	if (keycode == KEY_1)
	{
		image->isomatic = 1;
		image->x_axis = 0;
		image->y_axis = 0;
		image->z_axis = 0;
	}
	else
		image->isomatic = 0;
}

void	close_image(t_mlx *ptr)
{
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	free_map(ptr->image.map, ptr->image.map_row);
	exit(EXIT_SUCCESS);
}
