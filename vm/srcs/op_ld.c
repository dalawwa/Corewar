#include "corewar.h"

void	print_ld(t_arena *arena, t_exe *exe)
{
	int	i;

	i = 0;
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		if (exe->arg1->type == 'd' || exe->arg1->type == 'r')
			ft_printf("%d ", exe->arg1->d_data);
		else
			ft_printf("%hd ", (short)exe->arg1->d_data);
		ft_printf("r%hd\n", (short int)exe->arg2->d_value);
	}
}


int		op_ld(t_arena *arena, t_exe *exe)
{
	print_ld(arena, exe);
	if (exe->arg1->type != 'd' && exe->arg1->d_value > IDX_MOD)
	{
		exe->arg1->d_value = exe->arg1->d_value % IDX_MOD;
		free(exe->arg1->value);
		exe->arg1->value = ft_ito_hexa(exe->arg1->d_value);
	}
	exe->process->reg[exe->arg2->d_value][0] = exe->arg1->data[0];
	exe->process->reg[exe->arg2->d_value][1] = exe->arg1->data[1];
	exe->process->reg[exe->arg2->d_value][2] = exe->arg1->data[2];
	exe->process->reg[exe->arg2->d_value][3] = exe->arg1->data[3];
	print_exe_opts(arena, exe);
	is_carry_to_modify(exe);
	return (1);
}
