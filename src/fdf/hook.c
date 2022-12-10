/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:37:48 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 15:11:42 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	validated_keycode(int key)
{
	if (key == KEY_ESC || key == KEY_PLUS || key == KEY_MINUS || \
		(key >= KEY_LEFT && key <= KEY_UP) || (key >= KEY_A && key <= KEY_G) || \
		(key >= KEY_1 && key <= KEY_2))
		return (1);
	return (0);
}

int	key_hook(int keycode, t_mlx *ptr)
{
	if (validated_keycode(keycode))
	{
		if (keycode == KEY_PLUS || keycode == KEY_MINUS)
			zoom_image(&(ptr->image.per_distance), keycode);
		else if (keycode >= KEY_LEFT && keycode <= KEY_UP)
			move_image(&(ptr->image), keycode);
		else if (keycode >= KEY_A && keycode <= KEY_G)
			rotate_image(&(ptr->image), keycode);
		else if (keycode == KEY_1 || keycode == KEY_2)
			projection_image(&(ptr->image), keycode);
		else if (keycode == KEY_ESC)
			close_image(ptr);
		reset_image(ptr);
		draw_image(ptr);
	}
	return (EXIT_SUCCESS);
}

int	mouse_hook(t_mlx *ptr)
{
	close_image(ptr);
	return (EXIT_SUCCESS);
}
