#include "corewar.h"

int		main(int ac, char **av)
{
	t_arena		*arena;

	if ((arena = create_arena(ac, av)))
		go_match(arena);
	else
		print_usage();
	return (0);
}
