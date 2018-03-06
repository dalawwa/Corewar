#include "corewar.h"

int		is_valid_op(t_arena *arena, t_proc *proc)
{
	if (arena->mem[proc->pc] >= 1 && arena->mem[proc->pc] <= 16)
		return (1);
	return (0);
}
