#include "../so_long.h"

int get_pixel_canva(t_image *image, int x, int y)
{
	return *(unsigned int*) (image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8)));
}