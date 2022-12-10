/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:03:07 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 14:50:12 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*(str + 1) < '0' || *(str + 1) > '9')
			exit_error(NOT_INT);
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str != ',' && *str != 10)
	{
		if (*str < '0' || *str > '9')
			exit_error(NOT_INT);
		num = num * 10 + (*str - '0');
		if (num * sign < -2147483648 || num * sign > 2147483647)
			exit_error(NOT_INT);
		str++;
	}
	return ((int)num * sign);
}

int	fdf_rgb(char *rgb)
{
	int	idx;
	int	color;

	color = 0;
	while (*rgb)
	{
		idx = 0;
		while (idx < 16)
		{
			if (HEXA[idx] == ft_tolower(*rgb))
			{
				color = (16 * color) + idx;
				break ;
			}
			idx++;
		}
		rgb++;
	}
	return (color);
}

int	count_row(char *file)
{
	int		cnt;
	int		file_fd;
	char	*line;

	cnt = 0;
	assert_file_open(file_fd = open(file, O_RDONLY), file);
	line = get_next_line(file_fd);
	while (line && *line != '\n')
	{
		cnt++;
		free(line);
		line = get_next_line(file_fd);
	}
	free(line);
	close(file_fd);
	return (cnt);
}

int	count_col(char *file)
{
	int		cnt;
	int		file_fd;
	char	**line;

	cnt = 0;
	assert_file_open(file_fd = open(file, O_RDONLY), file);
	line = ft_split(get_next_line(file_fd), ' ');
	while (line[cnt])
	{
		free(line[cnt]);
		if (*line[cnt] == '\n')
			break ;
		cnt++;
	}
	free(line);
	close(file_fd);
	return (cnt);
}

void	set_points_distance(t_image *image)
{
	int	distance;
	int	col;
	int	row;

	distance = 1;
	col = image->map_col;
	row = image->map_row;
	while (col * distance < MID_X && row * distance < MID_Y)
		distance++;
	image->per_distance = distance;
}
