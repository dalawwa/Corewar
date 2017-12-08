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
	inc_pc(exe->process, exe->ocp_op->size_adv);
//	ft_printf("pc = %d char = %.2x\n", exe->process->pc, arena->mem[exe->process->pc]);
	return (0);
}
