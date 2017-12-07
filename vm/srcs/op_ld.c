#include "corewar.h"

int		op_ld(t_arena *arena, t_exe *exe)
{
	print_exe_opts(arena, exe);
	if (exe->arg1->type != 'd' && exe->arg1->d_value > IDX_MOD)
	{
		exe->arg1->d_value = exe->arg1->d_value % IDX_MOD;
		free(exe->arg1->value);
		exe->arg1->value = ft_ito_hexa(exe->arg1->d_value);
	}
/*	if (exe->arg1->type == 'd')
	{
		exe->process->reg[exe->arg2->d_value][0] = exe->arg1->value[0];
		exe->process->reg[exe->arg2->d_value][1] = exe->arg1->value[1];
		exe->process->reg[exe->arg2->d_value][2] = exe->arg1->value[2];
		exe->process->reg[exe->arg2->d_value][3] = exe->arg1->value[3];
	}
	else
	{*/
		exe->process->reg[exe->arg2->d_value][0] = exe->arg1->data[0];
		exe->process->reg[exe->arg2->d_value][1] = exe->arg1->data[1];
		exe->process->reg[exe->arg2->d_value][2] = exe->arg1->data[2];
		exe->process->reg[exe->arg2->d_value][3] = exe->arg1->data[3];
//	}
	is_carry_to_modify(exe);
	return (1);
}

// + 1 + 2 + 3 ATTENTION si mem[arg1->d_value + 3] > IDX_MOD_MOD
