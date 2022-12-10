/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:03:10 by eunson            #+#    #+#             */
/*   Updated: 2022/12/10 16:28:33 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_mlx	ptr;

	if (argc != 2)
		exit_error(ARGV_ERROR);
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, TITLE);
	ptr.img_ptr = mlx_new_image(ptr.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	init_image(&ptr, argv[1]);
	draw_image(&ptr);
	mlx_hook(ptr.win_ptr, 2, 0, key_hook, &ptr);
	mlx_hook(ptr.win_ptr, 17, 0, mouse_hook, &ptr);
	mlx_loop(ptr.mlx_ptr);
	return (EXIT_SUCCESS);
}
