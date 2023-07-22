#include "../so_long.h"

void avatar_sprite(t_avatar *avatar, int time)
{
	if(time % 30 == 0)
		avatar->sprite.x = 12;
}