#include "corewar.h"

int		op_st(t_arena *arena, t_exe *exe)
{
	if (exe->arg2->type == 'r')
	{
		exe->process->reg[exe->arg1->d_value][0] = exe->process->reg[exe->arg2->d_value][0];
		exe->process->reg[exe->arg1->d_value][1] = exe->process->reg[exe->arg2->d_value][1];
	}
	else
	{
		exe->process->reg[exe->arg1->d_value][0] = 0;
		exe->process->reg[exe->arg1->d_value][1] = arena->mem[exe->process->pc + (exe->arg2->d_value % IDX_MOD)];
	}
	is_carry_to_modify(exe);
	return (1);
}