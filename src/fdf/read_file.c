/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:31:41 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 16:37:10 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	**read_file(char *file)
{
	t_pixel		**map;
	int			row;
	int			file_fd;
	int			total_row;

	assert_file_open(file_fd = open(file, O_RDONLY), file);
	row = 0;
	total_row = count_row(file);
	map = (t_pixel **)malloc(sizeof(t_pixel *) * total_row);
	if (!map)
		exit_error(MALLOC_FAIL);
	while (row < total_row)
	{
		map[row] = make_pixels(get_next_line(file_fd), row);
		row++;
	}
	close(file_fd);
	return (map);
}
