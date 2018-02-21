#include "corewar.h"

int		op_live(t_arena *arena, t_exe *exe)
{
	int	i;

	i = 0;
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		ft_printf("%d\n", exe->arg1->d_data);
	}
	exe->process->nb_live++;
	arena->list_proc->nb_live_total++;
	exe->process->last_cycle_alive = arena->total_cycle;
	while (i < arena->nb_players)
	{
		// changement de logique car live reagit a play_live_num et pas a play_num
//		if (arena->players[i]->play_num == exe->arg1->d_value)
//		if (!ft_unsi_strcmp(arena->players[i]->play_live_num, exe->arg1->data))
		if (a_hexa_to_i(exe->arg1->data, 4) == a_hexa_to_i(arena->players[i]->play_live_num, 4))
		{
			arena->last_player_alive = arena->players[i];
			if (arena->opts->is_v1)
				ft_printf("Player %d (%s) is said to be alive\n", arena->players[i]->play_num, arena->players[i]->name);
			print_exe_opts(arena, exe);
			return (1);
		}
		i++;
	}
	print_exe_opts(arena, exe);
	return (0);
}
