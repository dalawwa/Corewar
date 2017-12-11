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
		// changement de logique
//		if (arena->players[i]->play_num == exe->arg1->d_value)
		if (!ft_unsi_strcmp(arena->players[i]->play_live_num, exe->arg1->data))
		{
			arena->last_player_alive = arena->players[i];
			if (arena->opts->is_v1)
				ft_printf("Player %d (%s) is said to be alive\n", arena->players[i]->play_num, arena->players[i]->name);
			return (1);
		}
		i++;
	}
	return (0);
}
