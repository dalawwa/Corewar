#include "corewar.h"

int		op_ld(t_arena *arena, t_exe *exe)
{
	if (exe->arg1->type == 'd')
		*find_reg_ptr(exe->arg2->d_value, exe) = (char)exe->arg1->d_value;
	else
		*find_reg_ptr(exe->arg2->d_value, exe) = (char)arena->mem[exe->arg1->d_value];
	return (1);
}
