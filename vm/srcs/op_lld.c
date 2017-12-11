#include "corewar.h"

int		op_lld(t_arena *arena, t_exe *exe)
{
	print_exe_opts(arena, exe);
/*	if (exe->arg1->type != 'd' && exe->arg1->d_value > IDX_MOD)
	{
		exe->arg1->d_value = exe->arg1->d_value % IDX_MOD;
		free(exe->arg1->value);
		exe->arg1->value = ft_ito_hexa(exe->arg1->d_value);
	}*/
	if (exe->arg1->type == 'd')
	{
		exe->process->reg[exe->arg2->d_value][0] = exe->arg1->value[0];
		exe->process->reg[exe->arg2->d_value][1] = exe->arg1->value[1];
		exe->process->reg[exe->arg2->d_value][2] = exe->arg1->value[2];
		exe->process->reg[exe->arg2->d_value][3] = exe->arg1->value[3];
	}
	else
	{
		if (exe->arg1->d_value > 0xfffffff)
		{
			ft_putendl("op_lld Failed");
			exe->process->carry = 0;
			return (0);
		}
		exe->process->reg[exe->arg2->d_value][0] = find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value, arena);
		exe->process->reg[exe->arg2->d_value][1] = find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value + 1, arena);
		exe->process->reg[exe->arg2->d_value][2] = find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value + 2, arena);
		exe->process->reg[exe->arg2->d_value][3] = find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value + 3, arena);
	}
	is_carry_to_modify(exe);
	return (1);
}

// + 1 + 2 + 3 ATTENTION si mem[arg1->d_va
