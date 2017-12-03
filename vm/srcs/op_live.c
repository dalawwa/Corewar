#include "corewar.h"

int		op_live(t_arena *arena, t_exe *exe)
{
	int	i;

	i = 0;
	exe->process->nb_live++;
	while (i < arena->nb_players)
	{
		if (arena->players[i]->play_num == exe->arg1->d_value)
		{
			arena->last_player_alive = arena->players[i]->play_num;
			return (1);
		}
		i++;
	}
	return (0);
}
