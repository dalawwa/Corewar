#include "corewar.h"

void		set_player_i(t_play *player_i, unsigned char *mem)
{
	int	i;

	i = 0;
	ft_printf("setup_players :\nName = %s\n body_len = %d\n", player_i->name,  player_i->body_len);
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
	ft_printf("arena->nb_players = %d\n", arena->nb_players);
	while (i < arena->nb_players)
	{
		set_player_i(arena->players[i], arena->mem);
		i++;
	}
	print_mem(arena);
	return (1);
}

