/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:30:28 by user              #+#    #+#             */
/*   Updated: 2023/08/13 17:49:16 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_pixel_canva(t_image *image, int x, int y, int pixel)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *) dst = pixel;
}

int	get_pixel_canva(t_image *image, int x, int y)
{
	return (*(unsigned int *)(image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8))));
}
