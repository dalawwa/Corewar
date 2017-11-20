#include "corewar.h"

int		main(int ac, char **av)
{
	t_arena		*arena;

	if ((arena = create_arena(ac, av)))
	{
		print_arena(arena);
		go_match(arena);
		free_arena(&arena);
	}
	else
		print_usage();
	return (0);
}
