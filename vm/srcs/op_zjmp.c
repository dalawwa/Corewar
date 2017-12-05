#include "corewar.h"

int		op_zjmp(t_arena *arena, t_exe *exe)
{
	print_exe_opts(arena, exe);
	if (exe->process->carry == 1)
	{
//		ft_printf("OLD PC = %d\n", exe->process->pc);
		inc_pc(exe->process, (short int)exe->arg1->d_value); // % IDX_MOD ???
//		ft_printf("NEW PC = %d\n", exe->process->pc);
		return (1);
	}
	return (0);
}
