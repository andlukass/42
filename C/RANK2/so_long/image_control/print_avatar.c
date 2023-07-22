#include "../so_long.h"

void print_avatar(t_image *canva, t_avatar *avatar)
{
	int indexX;
	int indexY;

	indexY = 0;
	while(indexY < avatar->sprite.height)
	{	
		indexX = 0;
		while(indexX < avatar->sprite.width)
		{
			if(get_pixel_canva(&avatar->body, avatar->sprite.x + indexX, avatar->sprite.y + indexY) != -16777216)
				put_pixel_canva(canva, (avatar->body.x + indexX), (avatar->body.y + indexY), get_pixel_canva(&avatar->body, avatar->sprite.x + indexX, avatar->sprite.y + indexY));
			indexX++;
		}
		indexY++;
	}
}