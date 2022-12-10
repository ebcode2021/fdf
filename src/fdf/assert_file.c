/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:24:47 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 15:58:19 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assert_file_open(int res, char *file)
{
	if (res == -1)
		system_error(file);
}

void	assert_file_data_cnt(char **data)
{
	int	num;

	num = 0;
	while (data[num])
		num++;
	if (!(num == 1 || num == 2))
		exit_error(UNALLOWED_DATA);
}

void	assert_rgb(char *rgb)
{
	if (!rgb)
		return ;
	if (ft_strncmp(rgb, "0x", 2) && ft_strncmp(rgb, "0X", 2))
		exit_error(NOT_RGB);
	rgb += 2;
	while (*rgb && *rgb != '\n')
	{
		*rgb = ft_tolower(*rgb);
		if (!((*rgb >= '0' && *rgb <= '9') || (*rgb >= 'a' && *rgb <= 'f')))
			exit_error(NOT_RGB);
		rgb++;
	}
}
