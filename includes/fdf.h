/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:19:00 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 15:23:18 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "const.h"
# include "error.h"
# include "libft.h"
# include "mlx.h"
# include "struct.h"

// assert_file.c
void	assert_file_open(int res, char *file);
void	assert_file_data_cnt(char **data);
void	assert_rgb(char *rgb);

// bresewnham.c
void	bresenham(t_image *img, t_pixel start, t_pixel end);

// draw_image.c
void	draw_image(t_mlx *ptr);
void	init_image(t_mlx *ptr, char *file);
void	reset_image(t_mlx *ptr);

// draw_map.c
void	draw_map(t_image *img);

// error.c
void	exit_error(char *str);
void	system_error(char *str);

// free.c
void	free_data(char **dataset);
void	free_map(t_pixel **map, int m_row);

// hook.c
int		key_hook(int keycode, t_mlx *ptr);
int		mouse_hook(t_mlx *ptr);

// image_event.c
void	zoom_image(int *distance, int keycode);
void	move_image(t_image *image, int keycode);
void	rotate_image(t_image *image, int keycode);
void	projection_image(t_image *image, int keycode);
void	close_image(t_mlx *ptr);

// pixel.c
void	draw_pixel(t_image *img, int x, int y, int color);
t_pixel	*make_pixels(char *dataset, int row);

// read_file.c
t_pixel	**read_file(char *file);

// rotate_axis.c
void	rotate_x(t_image *image, int x, int y, double theta);
void	rotate_y(t_image *image, int x, int y, double theta);
void	rotate_z(t_image *image, int x, int y, double theta);

// set_coordinate.c
void	set_coordinate(t_image *image);

// utils.c
int		count_row(char *file);
int		count_col(char *file);
int		fdf_atoi(const char *str);
int		fdf_rgb(char *rgb);
void	set_points_distance(t_image *image);

#endif