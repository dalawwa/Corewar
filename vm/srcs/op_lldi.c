#include "corewar.h"

int		op_lldi(t_arena *arena, t_exe *exe)
{
	uintmax_t result;

	result = (uintmax_t)exe->arg1->d_data + (uintmax_t)exe->arg2->d_data;
//	if (arena->opts->is_v4)
//		ft_printf("P   %d | lldi %d %d r%d\n", exe->process->player->play_num, exe->arg1->d_value, exe->arg2->d_value, exe->arg3->d_data);
	if (result > 0xffffffff)
	{
		ft_putendl("op_lldi failed");
		exe->process->carry = 0;
		return (0);
	}
//	result = result % IDX_MOD;
//	ft_printf("result = %u\n", result);
	exe->process->reg[exe->arg3->d_value][0] = find_char_at_mem_pc_adv(exe->process->pc, result, arena);
	exe->process->reg[exe->arg3->d_value][1] = find_char_at_mem_pc_adv(exe->process->pc, result + 1, arena);
	exe->process->reg[exe->arg3->d_value][2] = find_char_at_mem_pc_adv(exe->process->pc, result + 2, arena);
	exe->process->reg[exe->arg3->d_value][3] = find_char_at_mem_pc_adv(exe->process->pc, result + 3, arena);
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
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
		ft_printf("| -> load from %d + %d = %d (with pc %d)\n", exe->arg1->d_data, exe->arg2->d_data, exe->arg1->d_data + exe->arg2->d_data, exe->process->pc + exe->arg1->d_data + exe->arg2->d_data);
	}
	print_exe_opts(arena, exe);
//	ft_printf("carry Before %d\n", exe->process->carry);
	exe->process->carry = result ? 0 : 1;
//	ft_printf("carry After  %d\n", exe->process->carry);
	return (1);
}
/* attention si result + 3 > mem_size */
