#include "corewar.h"

int		op_aff(t_arena *arena, t_exe *exe)
{
	int	i;

	i = a_hexa_to_i(exe->process->reg[exe->arg1->d_value], 2) % 256;
	if (arena->opts->has_a == 1)
		ft_printf("Aff: %c\n", i);
	return (1);
}
