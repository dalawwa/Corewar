#include "corewar.h"

int		op_st(t_arena *arena, t_exe *exe)
{
	// a tester avec la vraie vm
	print_exe_opts(arena, exe);
//	ft_printf("PC = %d\n", exe->process->pc);
//	ft_putendl("in OP_ST");
	if (exe->arg2->type == 'r')
	{
		// ATTENTION Si d_value > NB_REG
		if (exe->arg2->d_value > REG_NUMBER)
			return (0);
		exe->process->reg[exe->arg2->d_value][0] = exe->process->reg[exe->arg1->d_value][0];
		exe->process->reg[exe->arg2->d_value][1] = exe->process->reg[exe->arg1->d_value][1];
		exe->process->reg[exe->arg2->d_value][2] = exe->process->reg[exe->arg1->d_value][2];
		exe->process->reg[exe->arg2->d_value][3] = exe->process->reg[exe->arg1->d_value][3];
	}
	else
	{
//		ft_printf("Process->pc = %d\n", exe->process->pc);
		arena->mem[exe->process->pc + (exe->arg2->d_value % IDX_MOD)] = exe->process->reg[exe->arg1->d_value][0];
		arena->mem[exe->process->pc + ((exe->arg2->d_value + 1) % IDX_MOD)] = exe->process->reg[exe->arg1->d_value][1];
		arena->mem[exe->process->pc + ((exe->arg2->d_value + 2) % IDX_MOD)] = exe->process->reg[exe->arg1->d_value][2];
		arena->mem[exe->process->pc + ((exe->arg2->d_value + 3) % IDX_MOD)] = exe->process->reg[exe->arg1->d_value][3];
	}
	is_carry_to_modify(exe);
	return (1);
}

/* PB : Dans else : mem = 1 char et reg = 2 char mais on doit mettre reg value dans mem[arg1]
 */
