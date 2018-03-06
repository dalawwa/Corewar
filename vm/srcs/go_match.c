#include "corewar.h"

void	put_starting_facts(t_arena *arena)
{
	int	i;

	i = 0;
	ft_putendl("Introducing contestants...");
	while (i < arena->nb_players)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", arena->players[i]->play_num, arena->players[i]->size, arena->players[i]->name, arena->players[i]->comment);
		i++;
	}
}

void		init_stat_match(t_arena **arena)
{
	(*arena)->ctd = CYCLE_TO_DIE;
	(*arena)->current_cycle = 0;
	(*arena)->total_cycle = 0;
	(*arena)->max_check = MAX_CHECKS;
	(*arena)->c_delta = CYCLE_DELTA;
}

void	go_match(t_arena *arena)
{
	if (arena)
	{
		put_starting_facts(arena);
		init_stat_match(&arena);
		start_match(arena);
	}
}
