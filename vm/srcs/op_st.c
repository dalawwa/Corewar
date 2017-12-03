#include "corewar.h"

int		op_st(t_arena *arena, t_exe *exe)
{
	// a tester avec la vraie vm
	if (exe->arg2->type == 'r')
	{
		exe->process->reg[exe->arg2->d_value][0] = exe->process->reg[exe->arg1->d_value][0];
		exe->process->reg[exe->arg2->d_value][1] = exe->process->reg[exe->arg1->d_value][1];
	}
	else
	{
		arena->mem[exe->process->pc + (exe->arg2->d_value % IDX_MOD)] = exe->process->reg[exe->arg1->d_value][0];
	}
	is_carry_to_modify(exe);
	return (1);
}

/* PB : Dans else : mem = 1 char et reg = 2 char mais on doit mettre reg value dans mem[arg1]
 */
