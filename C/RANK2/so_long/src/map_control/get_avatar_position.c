/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_avatar_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:51:23 by user              #+#    #+#             */
/*   Updated: 2023/07/31 17:04:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_avatar_position(t_avatar *avatar)
{
	avatar->position.line = (avatar->body.y / BIT_SIZE) + 1;
	avatar->position.x = (avatar->body.x / BIT_SIZE);
}
