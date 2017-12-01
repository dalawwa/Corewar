#include "corewar.h"

int		op_ld(t_arena *arena, t_exe *exe)
{
	if (exe->arg1->type == 'd')
	{
		if (exe->arg1->d_value > 0xfff)
			return (0);
		exe->process->reg[exe->arg2->d_value][0] = exe->arg1->value[2];
		exe->process->reg[exe->arg2->d_value][1] = exe->arg1->value[3];
	}
	else
	{
		exe->process->reg[exe->arg2->d_value][0] = 0;
		exe->process->reg[exe->arg2->d_value][1] = arena->mem[exe->arg1->d_value];
	}
	return (1);
}
