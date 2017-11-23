#include "corewar.h"

int		main(int ac, char **av)
{
	t_arena		*arena;

	if (ac == 1)
		print_usage();
	else
	{
		if ((arena = create_arena(ac, av)))
		{
			print_arena(arena);
			go_match(arena);
			free_arena(&arena);
		}
	}
	return (0);
}
