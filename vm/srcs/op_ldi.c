#include "corewar.h"

void	print_ldi(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
		ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
		if (exe->arg1->type == 'i')
			ft_printf("%d ", exe->arg1->d_data);
		else
			ft_printf("%hd ", (short int)exe->arg1->d_data);
		if (exe->arg2->type == 'r')
			ft_printf("%d ", exe->arg2->d_data);
		else
			ft_printf("%d ", exe->arg2->d_data);
		ft_printf("r%hd\n", (short int)exe->arg3->d_value);
		put_n_char(' ', intlen((short)(exe->process->process_num)));
		put_n_char(' ', 6);
		ft_printf("| -> load from %d + %d = %d (with pc and mod %d)\n", exe->arg1->d_data, exe->arg2->d_data, exe->arg1->d_data + exe->arg2->d_data, (exe->process->pc + exe->arg1->d_data + exe->arg2->d_data) % IDX_MOD);
	}

}


int		op_ldi(t_arena *arena, t_exe *exe)
{
	uintmax_t result;

	result = (uintmax_t)(exe->arg1->d_data + exe->arg2->d_data);
	print_ldi(arena, exe);
	print_exe_opts(arena, exe);
	//	if (result > 0xffffffff)
	//	{
	//		ft_putendl("op_ldi failed");
	//		return (0);
	//	}
	result = result % IDX_MOD;
	//	ft_printf("result = %u\n", result);
	exe->process->reg[exe->arg3->d_value][0] = find_char_at_mem_pc_adv(exe->process->pc, result, arena);
	exe->process->reg[exe->arg3->d_value][1] = find_char_at_mem_pc_adv(exe->process->pc, result + 1, arena);
	exe->process->reg[exe->arg3->d_value][2] = find_char_at_mem_pc_adv(exe->process->pc, result + 2, arena);
	exe->process->reg[exe->arg3->d_value][3] = find_char_at_mem_pc_adv(exe->process->pc, result + 3, arena);
	return (1);
}
/* attention si result + 3 > mem_size */
