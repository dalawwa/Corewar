#include "corewar.h"

int		op_lldi(t_arena *arena, t_exe *exe)
{
	uintmax_t result;

	result = (uintmax_t)exe->arg1->d_data + (uintmax_t)exe->arg2->d_data;
	if (result > 0xffffffff)
	{
		ft_putendl("op_ldi failed");
		exe->process->carry = 0;
		return (0);
	}
//	result = result % IDX_MOD;
	ft_printf("result = %u\n", result);
	exe->process->reg[exe->arg3->d_value][0] = arena->mem[exe->process->pc + result];
	exe->process->reg[exe->arg3->d_value][1] = arena->mem[exe->process->pc + result + 1];
	exe->process->reg[exe->arg3->d_value][2] = arena->mem[exe->process->pc + result + 2];
	exe->process->reg[exe->arg3->d_value][3] = arena->mem[exe->process->pc + result + 3];
	is_carry_to_modify(exe);
	return (1);
}
/* attention si result + 3 > mem_size */
