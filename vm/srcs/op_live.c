#include "corewar.h"

int		op_live(t_arena *arena, t_exe *exe)
{
	int	i;

	i = 0;
	print_exe_opts(arena, exe);
	exe->process->nb_live++;
	arena->list_proc->nb_live_total++;
	exe->process->last_cycle_alive = arena->total_cycle;
	while (i < arena->nb_players)
	{
		if (arena->players[i]->play_num == exe->arg1->d_value)
		{
			arena->last_player_alive = arena->players[i];
			return (1);
		}
		i++;
	}
	return (0);
}
