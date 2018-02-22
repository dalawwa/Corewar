#include "corewar.h"

int		op_fork(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		if (exe->arg1->d_value > 0x7fff)
			ft_printf("%hd (%hd)\n", exe->arg1->d_value, (short)(((exe->arg1->d_value + exe->process->pc) - 0x10000) % IDX_MOD));
		else
			ft_printf("%hd (%hd)\n", exe->arg1->d_value, (short)(((exe->arg1->d_value + exe->process->pc)) % IDX_MOD));

	}
	print_exe_opts(arena, exe);
	create_new_process(arena, exe->process->player, exe->process);
//	ft_putendl("POST FORK");
//	print_all_process(arena);
//	arena->list_proc->last->
	return (1);
}
