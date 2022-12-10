/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:43:31 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 14:44:15 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return ;
	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

t_pixel	init_pixel(int col, int row, char *z, char *rgb)
{
	t_pixel	pixel;

	pixel.x = col;
	pixel.y = row;
	pixel.z = fdf_atoi(z);
	pixel.z_value = pixel.z;
	assert_rgb(rgb);
	if (rgb)
		pixel.rgb = fdf_rgb(rgb);
	else
		pixel.rgb = fdf_rgb(DEFAULT_RGB);
	return (pixel);
}

t_pixel	*make_pixels(char *dataset, int row)
{
	int			col;
	int			total_col;
	char		**line;
	char		**data;
	t_pixel		*pixels;

	col = 0;
	total_col = 0;
	line = ft_split(dataset, ' ');
	while (line[total_col] && *line[total_col] != '\n')
		total_col++;
	pixels = (t_pixel *)malloc(sizeof(t_pixel) * total_col);
	if (!pixels)
		exit_error(MALLOC_FAIL);
	while (line[col] && *line[col] != '\n')
	{
		data = ft_split(line[col], ',');
		assert_file_data_cnt(data);
		pixels[col] = init_pixel(col, row, data[0], data[1]);
		free_data(data);
		col++;
	}
	free(line[col]);
	free(line);
	return (pixels);
}
