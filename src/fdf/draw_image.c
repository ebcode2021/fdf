/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:52:09 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 14:24:10 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_image(t_mlx *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	set_coordinate(&(ptr->image));
	draw_map(&(ptr->image));
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}

void	reset_image(t_mlx *ptr)
{
	t_image	*image;

	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	image = &(ptr->image);
	image->addr = mlx_get_data_addr(ptr->img_ptr, &image->bpp, \
									&image->size_line, &image->endian);
}

void	init_image(t_mlx *ptr, char *file)
{
	t_image	*image;

	image = &(ptr->image);
	image->addr = mlx_get_data_addr(ptr->img_ptr, &image->bpp, \
									&image->size_line, &image->endian);
	image->map = read_file(file);
	image->map_row = count_row(file);
	image->map_col = count_col(file);
	image->x_axis = 0;
	image->y_axis = 0;
	image->z_axis = 0;
	image->x_move = 0;
	image->y_move = 0;
	image->z_move = 0;
	image->isomatic = 1;
	set_points_distance(image);
}
