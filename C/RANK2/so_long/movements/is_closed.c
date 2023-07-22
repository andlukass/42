#include "../so_long.h"

static int down_closed(t_avatar *avatar, int line, int x, char **map)
{
	if(map[line+1][x+1] == '1' &&
		avatar->body.x % 32 != 0)
		x++;
	if(map[line+1][x] != '1' || avatar->body.y % 32 == 0)
		return ('0');
	if(avatar->direction == 'd')
		return ('d');
	else
		return ('0');
}

static char left_closed(t_avatar *avatar, int line, int x, char **map)
{
	if(map[line][x - 1] != '1' || avatar->body.x % 32 != 0)
		return ('0');
	if(avatar->direction == 'l')
		return ('l');
	else
		return ('0');
}

static char up_closed(t_avatar *avatar, int line, int x, char **map)
{
	if(map[line-1][x+1] == '1' &&
		avatar->body.x % 32 != 0)
		x++;
	if(map[line-1][x] != '1' || avatar->body.y % 32 != 0)
		return ('0');
	if(avatar->direction == 'u')
		return ('u');
	else
		return ('0');
}

static char rigth_closed(t_avatar *avatar, int line, int x, char **map)
{
	if(map[line][x+1] != '1')
		return ('0');
	if(avatar->direction == 'r')
		return ('r');
	else
		return ('0');
}

char is_closed(t_avatar *avatar, int line, int x, char **map)
{
	char result;

	result = '0';
	if(left_closed(avatar, line, x, map) != '0')
		result = left_closed(avatar, line, x, map);
	if(rigth_closed(avatar, line, x, map) != '0')
		result = rigth_closed(avatar, line, x, map);
	if(up_closed(avatar, line, x, map) != '0')
		result = up_closed(avatar, line, x, map);
	if(down_closed(avatar, line, x, map) != '0')
		result = down_closed(avatar, line, x, map);
	return (result);
}
