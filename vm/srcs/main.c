#include "corewar.h"

int		init_arena(t_arena **arena)
{
	if (!(*arena = (t_arena *)malloc(sizeof(t_arena))))
		return (0);
	(*arena)->players = NULL;
	(*arena)->bdd = NULL;
	(*arena)->list_proc = NULL;
	(*arena)->opts = NULL;
	(*arena)->files = NULL;
	(*arena)->nb_players = 0;
	(*arena)->ctd = CYCLE_TO_DIE;
	(*arena)->current_cycle = 0;
	(*arena)->current_nb_check = 0;
	(*arena)->max_check = MAX_CHECKS;
	(*arena)->c_delta = CYCLE_DELTA;
	(*arena)->last_player_alive = 0;
	return (1);
}

int		main(int ac, char **av)
{
	t_arena		*arena;

	arena = NULL;
	if (ac == 1)
		print_usage();
	else
	{
		if (init_arena(&arena) == 0)
			return (0);
		if ((create_arena(ac, av, &arena)) != 0)
			go_match(arena);
		free_arena(&arena);
	}
	return (0);
}
