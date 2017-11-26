#include "corewar.h"

int		initialized_start_process(t_arena *arena)
{
	int		i;

	i = 0;
	while (i < arena->nb_players)
	{
		if ((create_new_process(arena, arena->players[i], NULL)) == 0)
			return (0);
		i++;
	}
	print_all_process(arena);
	return (1);
}
