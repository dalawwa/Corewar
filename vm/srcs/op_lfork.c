#include "corewar.h"

int		op_lfork(t_arena *arena, t_exe *exe)
{
	print_exe_opts(arena, exe);
	create_new_process(arena, exe->process->player, exe->process);
	return (1);
}
