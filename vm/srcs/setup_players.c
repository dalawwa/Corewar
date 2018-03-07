#include "corewar.h"

void	set_player_i(t_play *player_i, unsigned char *mem)
{
	int	i;

	i = 0;
	while (i < player_i->body_len)
	{
		mem[player_i->idx_start + i] = player_i->body[i];
		i++;
	}
}

int		setup_players(t_arena *arena)
{
	int	i;

	i = 0;
	while (i < arena->nb_players)
	{
		set_player_i(arena->players[i], arena->mem);
		i++;
	}
	return (1);
}