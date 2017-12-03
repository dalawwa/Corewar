#include "corewar.h"

int		op_lfork(t_arena *arena, t_exe *exe)
{
	create_new_process(arena, exe->process->player, exe->process);
	return (1);
}
