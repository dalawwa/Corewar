#include "corewar.h"

int		create_mem(t_arena *arena)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		arena->mem[i] = 0;
		i++;
	}
	print_mem(arena);
	return (1);
}
