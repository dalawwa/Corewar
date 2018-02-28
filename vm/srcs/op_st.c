#include "corewar.h"


void	print_st(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
//		ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
		/*
		ft_putchar('P');
		put_n_char(' ', 5 - intlen((short)exe->process->process_num));
		*/
		print_proc_num_name(exe);
		ft_printf("r%hd ", (short int)exe->arg1->d_value);
		ft_printf("%hd\n", (short int)exe->arg2->d_value);
	}
}

int		op_st(t_arena *arena, t_exe *exe)
{
	int result;
	int mod;

	result = 0;
	mod = 0;
	// a tester avec la vraie vm
	print_st(arena, exe);
//		ft_printf("PC = %d\n", exe->process->pc);
	//	ft_putendl("in OP_ST");
	// if (exe->arg2->type == 'r')
	// {
	// 	exe->process->reg[exe->arg2->d_value][0] = exe->process->reg[exe->arg1->d_value][0];
	// 	exe->process->reg[exe->arg2->d_value][1] = exe->process->reg[exe->arg1->d_value][1];
	// 	exe->process->reg[exe->arg2->d_value][2] = exe->process->reg[exe->arg1->d_value][2];
	// 	exe->process->reg[exe->arg2->d_value][3] = exe->process->reg[exe->arg1->d_value][3];
	// }
	// else
	// {
		//		ft_printf("Process->pc = %d\n", exe->process->pc);
		/*
		arena->mem[find_pc_adv(exe->process->pc, exe->arg2->d_value % IDX_MOD, 1)] = exe->process->reg[exe->arg1->d_value][0];
		arena->mem[find_pc_adv(exe->process->pc, exe->arg2->d_value % IDX_MOD + 1, 1)] = exe->process->reg[exe->arg1->d_value][1];
		arena->mem[find_pc_adv(exe->process->pc, exe->arg2->d_value % IDX_MOD + 2, 1)] = exe->process->reg[exe->arg1->d_value][2];
		arena->mem[find_pc_adv(exe->process->pc, exe->arg2->d_value % IDX_MOD + 3, 1)] = exe->process->reg[exe->arg1->d_value][3];
		*/
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
//	ft_printf("Result = %d\n", result);
	mod = result;
	// mod = exe->process->pc + result;
	// ft_printf("Mod = %d\n", mod);
	// ft_printf("MEM_SIZE - result - PC = %d\n", MEM_SIZE - result - exe->process->pc);
	// if (mod < 0)
	// 	mod = mod % -MEM_SIZE;
	// else
	// 	mod = mod % MEM_SIZE;
	// ft_printf("MODULO\nMod = %d\n", mod);
		arena->mem[mod] = exe->process->reg[exe->arg1->d_value][0];
		arena->mem[get_adv(mod + 1)] = exe->process->reg[exe->arg1->d_value][1];
		arena->mem[get_adv(mod + 2)] = exe->process->reg[exe->arg1->d_value][2];
		arena->mem[get_adv(mod + 3)] = exe->process->reg[exe->arg1->d_value][3];
	// }
	print_exe_opts(arena, exe);
	is_carry_to_modify(exe);
	return (1);
}

/* PB : Dans else : mem = 1 char et reg = 2 char mais on doit mettre reg value dans mem[arg1]
*/
