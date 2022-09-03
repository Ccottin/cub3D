#include "header.h"

int	set_dir(t_data *data, char player_dir)
{
	if (player_dir == 'N')
	{
		data->caster.dirplayerx = 0;
		data->caster.dirplayery = -1;
		data->caster.planex = 0.6;
		data->caster.planey = 0;

	}
	if (player_dir == 'S')
	{
		data->caster.dirplayerx = 0;
		data->caster.dirplayery = 1;
		data->caster.planex = 0.6;
		data->caster.planey = 0;

	}
	if (player_dir == 'E')
	{
		data->caster.dirplayerx = 1;
		data->caster.dirplayery = 0;
		data->caster.planex = 0;
		data->caster.planey = 0.6;

	}
	if (player_dir == 'O')
	{
		data->caster.dirplayerx = -1;
		data->caster.dirplayery = 0;
		data->caster.planex = 0;
		data->caster.planey = 0.6;

	}
	return (0);
}

int	init_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->map.map[y]	&& !is_char_acter(data->map.map[y][x]))
	{
		x = 0;
		while (data->map.map[y][x] && !is_char_acter(data->map.map[y][x]))
			x++;
		if (!is_char_acter(data->map.map[y][x]))
			y++;
	}
	data->caster.playerx = x;
	data->caster.playery = y;
	printf("player pos = %f, %f\n", data->caster.playerx, data->caster.playery);
	return (set_dir(data, data->map.map[y][x]));
}

