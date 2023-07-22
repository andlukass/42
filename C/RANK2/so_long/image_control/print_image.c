#include "../so_long.h"

void print_image(t_image *canva, t_image *image, int x, int y)
{
	int indexX;
	int indexY;

	indexY = 0;
	while(indexY < image->height)
	{
		indexX = 0;
		while(indexX < image->width)
		{
			if(get_pixel_canva(image, indexX, indexY)!= -16777216)
				put_pixel_canva(canva, (x + indexX), (y + indexY), get_pixel_canva(image, indexX, indexY));
			indexX++;
		}
		indexY++;
	}
}