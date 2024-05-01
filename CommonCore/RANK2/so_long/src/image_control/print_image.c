/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:54:41 by user              #+#    #+#             */
/*   Updated: 2023/07/27 20:29:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_image(t_image *canva, t_image *image, int x, int y)
{
	int	index_x;
	int	index_y;

	index_y = 0;
	while (index_y < image->height)
	{
		index_x = 0;
		while (index_x < image->width)
		{
			if (get_pixel_canva(image, index_x, index_y) != -16777216)
			{
				put_pixel_canva(canva, (x + index_x), (y + index_y),
					get_pixel_canva(image, index_x, index_y));
			}
			index_x++;
		}
		index_y++;
	}
}
