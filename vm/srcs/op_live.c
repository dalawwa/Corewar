#include "corewar.h"

int		op_live(t_arena *arena, t_exe *exe)
{
	int	i;

	i = 0;
	if (arena->opts->is_v1 && exe->bdd_op->opcode == 1)
			ft_printf("Player %d (%s) is said to be alive\n", exe->process->player->play_num, exe->process->player->name);
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
