#include "corewar.h"

int		op_ld(t_arena *arena, t_exe *exe)
{
	if (exe->arg1->type == 'd')
	{
		ft_printf("AVANT MODULO : exe->arg1->value = %d\n", exe->arg1->d_value);
		if (exe->arg1->d_value > IDX_MOD)
		{
			exe->arg1->d_value = exe->arg1->d_value % IDX_MOD;
			ft_printf("AFTER MODULO : exe->arg1->d_value = %d\n", exe->arg1->d_value);
			free(exe->arg1->value);
			exe->arg1->value = ft_ito_hexa(exe->arg1->d_value);
		}
		ft_printf("NEW arg1->value = %x\n", exe->arg1->value);
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
