#include "corewar.h"

int		is_carry_to_modify(t_exe *exe)
{
	if ((exe->opcode >= 4 && exe->opcode <= 6) || exe->opcode == 14)
	{
		if (exe->arg1 == 0 || exe->arg2 == 0 || exe->arg3 == 0)
			exe->process->carry = 1;
		else
			exe->process->carry = 0;
	}
	return (0);
}
