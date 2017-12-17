#include "corewar.h"

int		op_fork(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
		if (exe->arg1->d_value > 0x7fff)
			ft_printf("P    %d | %s %hd (%hd)\n", exe->process->process_num, exe->bdd_op->name, exe->arg1->d_value, (short)(((exe->arg1->d_value + exe->process->pc) - 0x10000) % IDX_MOD));
		else
			ft_printf("P    %d | %s %hd (%hd)\n", exe->process->process_num, exe->bdd_op->name, exe->arg1->d_value, (short)(((exe->arg1->d_value + exe->process->pc)) % IDX_MOD));

	}
	print_exe_opts(arena, exe);
	create_new_process(arena, exe->process->player, exe->process);
//	ft_putendl("POST FORK");
//	print_all_process(arena);
//	arena->list_proc->last->
	return (1);
}
