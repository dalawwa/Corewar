#include "corewar.h"


void	print_st(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		ft_printf("r%hd ", (short int)exe->arg1->d_value);
		ft_printf("%hd\n", (short int)exe->arg2->d_value);
	}
}

int		op_st(t_arena *arena, t_exe *exe)
{
	int result;

	result = 0;
	print_st(arena, exe);
	result = exe->arg2->d_value % IDX_MOD;
	if (exe->arg2->d_value < 0x8000)
	{
		result = exe->process->pc + result;
		if (result >= MEM_SIZE)
			result = result - MEM_SIZE;
	}
	else
	{
		result = IDX_MOD - result;
		if (result == 512)
			result = 0;
		result = exe->process->pc - result;
		if (result < 0)
			result = MEM_SIZE + result;
	}
	arena->mem[get_adv(result)] = exe->process->reg[exe->arg1->d_value][0];
	arena->mem[get_adv(result + 1)] = exe->process->reg[exe->arg1->d_value][1];
	arena->mem[get_adv(result + 2)] = exe->process->reg[exe->arg1->d_value][2];
	arena->mem[get_adv(result + 3)] = exe->process->reg[exe->arg1->d_value][3];
	print_exe_opts(arena, exe);
	is_carry_to_modify(exe);
	return (1);
}
