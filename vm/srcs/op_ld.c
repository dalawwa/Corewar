#include "corewar.h"

int		op_ld(t_arena *arena, t_exe *exe)
{
	if (exe->arg1->type == 'd')
		arena = arena + 0;
//		exe->process->reg[exe->arg2->d_value] = (char)exe->arg1->d_value;
//	else
//		*find_reg_ptr(exe->arg2->d_value] = (char)arena->mem[exe->arg1->d_value];
	return (1);
}
