#include "corewar.h"



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
		{
			print_arena(arena);
			go_match(arena);
		}
		free_arena(&arena);
//			ft_putendl("WHAT THE FUCK ");
	}
//	while (1);
	return (0);
}
