#include "corewar.h"

int		op_fork(t_arena *arena, t_exe *exe)
{
//	ft_printf("\n\nFORK: arena->mem[exe->process->pc]: %d\n\n\n", arena->mem[exe->process->pc]);
	if (arena->mem[exe->process->pc] == 0)
	{
		exe->arg1->value[0] = arena->mem[exe->process->pc + 1];
		exe->arg1->value[1] = arena->mem[exe->process->pc + 2];
		exe->arg1->d_value = a_hexa_to_i(exe->arg1->value, 2);
		exe->arg1->d_data = exe->arg1->d_value;
	}
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
