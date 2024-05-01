/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:54:53 by user              #+#    #+#             */
/*   Updated: 2023/07/27 20:27:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_mlx_image(t_image *image, void *mlx, char *source, int *endian)
{
	image->id = mlx_xpm_file_to_image(mlx,
			source, &image->width, &image->height);
	image->addr = mlx_get_data_addr(image->id,
			&image->bits_per_pixel, &image->line_length, endian);
}
