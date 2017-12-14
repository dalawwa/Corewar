#include "corewar.h"

int		op_sti(t_arena *arena, t_exe *exe)
{
	uintmax_t result;

	result = (uintmax_t)exe->arg2->d_data + (uintmax_t)exe->arg3->d_data;
	if (result > 0xffffffff)
	{
		ft_putendl("op_sti failed");
		return (0);
	}
	result = result % IDX_MOD;
//	ft_printf("result = %u\n", result);
	arena->mem[find_pc_adv(exe->process, result)] = exe->process->reg[exe->arg1->d_value][0];
	arena->mem[find_pc_adv(exe->process, result + 1)] = exe->process->reg[exe->arg1->d_value][1];
	arena->mem[find_pc_adv(exe->process, result + 2)] = exe->process->reg[exe->arg1->d_value][2];
	arena->mem[find_pc_adv(exe->process, result + 3)] = exe->process->reg[exe->arg1->d_value][3];
	if (arena->opts->is_v4)
	{
		ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
		ft_printf("r%d ", exe->arg1->d_value);
		if (exe->arg2->type == 'i')
			ft_printf("%d ", exe->arg2->d_data);
		else if (exe->arg2->type == 'r')
			ft_printf("%d ", exe->arg2->d_data);
		else
			ft_printf("%hd ", (short)exe->arg2->d_data);
		ft_printf("%hd", (short)exe->arg3->d_data);
		ft_putchar('\n');
		put_n_char(' ', intlen((short)(exe->process->process_num)));
		put_n_char(' ', 6);
		ft_printf("| -> store to %d + %hd = %d (with pc and mod %hd)\n", exe->arg2->d_data, (short)exe->arg3->d_data, ((exe->arg3->d_data + exe->arg2->d_data) % IDX_MOD), (short)(exe->process->pc + (exe->arg2->d_data + (short)exe->arg3->d_data) % IDX_MOD));
	}
	print_exe_opts(arena, exe);
	return (1);
}
/* attention si result + 3 > mem_size */
