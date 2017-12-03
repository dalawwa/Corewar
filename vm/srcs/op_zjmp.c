#include "corewar.h"

int		op_zjmp(t_arena *arena, t_exe *exe)
{
	if (exe->process->carry == 1)
	{
		exe->process->pc = exe->arg1->d_value; // % IDX_MOD ???
		return (1);
	}
	return (0);
}
