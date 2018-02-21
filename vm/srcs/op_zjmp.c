#include "corewar.h"

int		op_zjmp(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		ft_printf("%hd", (short)exe->arg1->d_value);
		if (exe->process->carry == 1)
			ft_printf(" OK\n");
		else
		{
			ft_printf(" FAILED\n");
			print_exe_opts(arena, exe);
		}
	}
	if (exe->process->carry == 1)
	{
//		ft_printf("DBG OLD PC = %d\n", exe->process->pc);
		inc_pc(exe->process, (short int)exe->arg1->d_value); // % IDX_MOD ???
//		ft_printf("DEBG NEW PC = %d\n", exe->process->pc);
		return (1);
	}
//	ft_printf("DEBG old pc = %d char = %.2x\n", exe->process->pc, arena->mem[exe->process->pc]);
	inc_pc(exe->process, exe->ocp_op->size_adv);
//	ft_printf("DEBG NEW pc = %d char = %.2x\n", exe->process->pc, arena->mem[exe->process->pc]);
	return (0);
}
