#include "corewar.h"

int		op_ld(t_arena *arena, t_exe *exe)
{
	if (exe->arg1->type == 'd')
	{
		exe->process->reg[exe->arg2->d_value][0] = exe->arg1->value[0];
		exe->process->reg[exe->arg2->d_value][1] = exe->arg1->value[1];
	}
	else
	{
		exe->process->reg[exe->arg2->d_value][0] = 0;
		exe->process->reg[exe->arg2->d_value][1] = arena->mem[exe->arg1->d_value];
	}
	return (1);
}
