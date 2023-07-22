#include "../so_long.h"

static void move_sprite(t_avatar *avatar, int initial)
{
	avatar->sprite.y = initial;
	avatar->sprite.x = avatar->sprite.x + 64;
	if(avatar->sprite.x > 400)
		avatar->sprite.x = 10;
}

static void move_down(t_avatar *avatar, int line, int x, char **map)
{
	move_sprite(avatar, 9);
	if(map[line+1][x+1] == '1' &&
		avatar->body.x % 32 != 0)
		x++;
	if(map[line+1][x] != '1' ||
		avatar->body.y % 32 == 0)
		avatar->body.y = avatar->body.y + PLAYER_SPEED;
}

static void move_up(t_avatar *avatar, int line, int x, char **map)
{
	move_sprite(avatar, 200);
	if(map[line-1][x+1] == '1' &&
		avatar->body.x % 32 != 0)
		x++;
	if(map[line-1][x] != '1' ||
		avatar->body.y % 32 != 0)
		avatar->body.y = avatar->body.y - PLAYER_SPEED;
}

static void move_rigth(t_avatar *avatar, int line, int x, char **map)
{
	move_sprite(avatar, 135);
	if(map[line][x+1] != '1')
		avatar->body.x = avatar->body.x + PLAYER_SPEED;
}

static void move_left(t_avatar *avatar, int line, int x, char **map)
{
	move_sprite(avatar, 70);
	if(map[line][x - 1] != '1' || avatar->body.x % 32 != 0)
		avatar->body.x = avatar->body.x - PLAYER_SPEED;
}

void move_player(t_avatar *avatar, int line, int x, char **map, char dir)
{
	if(dir == 'u')
		move_up(avatar, line, x, map);
	if(dir == 'd')
		move_down(avatar, line, x, map);
	if(dir == 'l')
		move_left(avatar, line, x, map);
	if(dir == 'r')
		move_rigth(avatar, line, x, map);
}