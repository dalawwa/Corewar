#include "corewar.h"

int		op_fork(t_arena *arena, t_exe *exe)
{
	print_exe_opts(arena, exe);
	create_new_process(arena, exe->process->player, exe->process);
//	arena->list_proc->last->
	return (1);
}