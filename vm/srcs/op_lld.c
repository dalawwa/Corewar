#include "corewar.h"

int		op_lld(t_arena *arena, t_exe *exe)
{
	if (exe->arg1->type == 'd')
	{
		exe->process->reg[exe->arg2->d_value][0] = exe->arg1->value[0];
		exe->process->reg[exe->arg2->d_value][1] = exe->arg1->value[1];
		exe->process->reg[exe->arg2->d_value][2] = exe->arg1->value[2];
		exe->process->reg[exe->arg2->d_value][3] = exe->arg1->value[3];
	}
	else
	{
		exe->process->reg[exe->arg2->d_value][0] = find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value, arena);
		exe->process->reg[exe->arg2->d_value][1] = find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value + 1, arena);
		exe->process->reg[exe->arg2->d_value][2] = find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value + 2, arena);
		exe->process->reg[exe->arg2->d_value][3] = find_char_at_mem_pc_adv(exe->process->pc, exe->arg1->d_value + 3, arena);
	}
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		if (exe->arg1->type == 'd')
			ft_printf("%d ", exe->arg1->d_data);
		else
			ft_printf("%hd ", exe->arg1->d_data);
		if (exe->arg2->type == 'i')
			ft_printf("%d", exe->arg2->d_data);
		else if (exe->arg2->type == 'r')
			ft_printf("r%d", exe->arg2->d_value);
		else
			ft_printf("%hd", (short)exe->arg2->d_data);
		ft_putchar('\n');
	}
	print_exe_opts(arena, exe);
	is_carry_to_modify(exe);
	return (1);
}
