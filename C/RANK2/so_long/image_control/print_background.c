#include "../so_long.h"

void print_background(t_image *canva, t_image *image, int y, int x)
{
	int indexY;
	int indexX;

	indexY = 0;
	while(indexY < y)
	{
		indexX = 0;
		while(indexX < x)
		{
			print_image(canva, image, indexX, indexY);
			indexX = indexX + BIT_SIZE;
		}
		indexY = indexY + BIT_SIZE;
	}
}