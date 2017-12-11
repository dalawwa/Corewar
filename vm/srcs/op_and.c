#include "corewar.h"

int		op_and(t_arena *arena, t_exe *exe)
{
	uintmax_t		result;
	unsigned char	*s;

//	print_exe_opts(arena, exe);
	result = (uintmax_t)(exe->arg1->d_data & exe->arg2->d_data);
//	ft_printf("op_AND : Result = %u\n", result);
/*	if (result > 0xffffffff)
	{
		ft_putendl("op_and FAILED");
		exe->process->carry = 0;
		return (0);
	}*/
	s = ft_ito_hexa(result);
	if (s == NULL)
		return (-1);
	exe->process->reg[exe->arg3->d_value][0] = s[0];
	exe->process->reg[exe->arg3->d_value][1] = s[1];
	exe->process->reg[exe->arg3->d_value][2] = s[2];
	exe->process->reg[exe->arg3->d_value][3] = s[3];
	free(s);
	if (arena->opts->is_v4)
	{
		ft_printf("P    %d | %s ", exe->process->process_num, exe->bdd_op->name);
		if (exe->arg1->type == 'i')
			ft_printf("%d ", exe->arg1->d_data - MEM_SIZE);
		else
			ft_printf("%hd ", (short)exe->arg1->d_data);
		if (exe->arg1->type == 'i')
			ft_printf("%d ", exe->arg2->d_data);
		else
			ft_printf("%hd ", (short)exe->arg2->d_data);
		ft_printf("r%d", (short)(exe->arg3->d_value));
		ft_putchar('\n');
	}
	s = NULL;
	is_carry_to_modify(exe);
	return (1);
}
