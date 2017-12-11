#include "corewar.h"

int		op_fork(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
		ft_printf("P    %d | %s %d (%d)\n", exe->process->process_num, exe->bdd_op->name, exe->arg1->d_value, exe->arg1->d_value % IDX_MOD + exe->process->pc);
	}
	print_exe_opts(arena, exe);
	create_new_process(arena, exe->process->player, exe->process);
//	ft_putendl("POST FORK");
//	print_all_process(arena);
//	arena->list_proc->last->
	return (1);
}
