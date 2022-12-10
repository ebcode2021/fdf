/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:43:57 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 14:27:27 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_pixel
{
	int		x;
	int		y;
	int		z;
	int		z_value;
	int		rgb;
}	t_pixel;

typedef struct s_image
{
	t_pixel		**map;
	void		*addr;
	double		x_axis;
	double		y_axis;
	double		z_axis;
	int			x_move;
	int			y_move;
	int			z_move;
	int			map_col;
	int			map_row;
	int			per_distance;
	int			bpp;
	int			size_line;
	int			endian;
	int			isomatic;
}	t_image;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	struct s_image	image;
}	t_mlx;

#endif