#include "corewar.h"

int		op_lldi(t_arena *arena, t_exe *exe)
{
	uintmax_t result;

	result = (uintmax_t)exe->arg1->d_data + (uintmax_t)exe->arg2->d_data;
	print_exe_opts(arena, exe);
	if (result > 0xffffffff)
	{
		ft_putendl("op_lldi failed");
		exe->process->carry = 0;
		return (0);
	}
//	result = result % IDX_MOD;
	ft_printf("result = %u\n", result);
	exe->process->reg[exe->arg3->d_value][0] = find_char_at_mem_pc_adv(exe->process->pc, result, arena);
	exe->process->reg[exe->arg3->d_value][1] = find_char_at_mem_pc_adv(exe->process->pc, result + 1, arena);
	exe->process->reg[exe->arg3->d_value][2] = find_char_at_mem_pc_adv(exe->process->pc, result + 2, arena);
	exe->process->reg[exe->arg3->d_value][3] = find_char_at_mem_pc_adv(exe->process->pc, result + 3, arena);
	is_carry_to_modify(exe);
	return (1);
}
/* attention si result + 3 > mem_size */
