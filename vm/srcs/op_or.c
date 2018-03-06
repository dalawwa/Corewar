#include "corewar.h"

int		op_or(t_arena *arena, t_exe *exe)
{
	uintmax_t		result;
	unsigned char	*s;

	result = (uintmax_t)(exe->arg1->d_data | exe->arg2->d_data);
	s = ft_ito_hexa(result);
	if (s == NULL)
		return (-1);
	exe->process->reg[exe->arg3->d_value][0] = s[0];
	exe->process->reg[exe->arg3->d_value][1] = s[1];
	exe->process->reg[exe->arg3->d_value][2] = s[2];
	exe->process->reg[exe->arg3->d_value][3] = s[3];
	free(s);
	s = NULL;
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		ft_printf("%d ", exe->arg1->d_data);
		ft_printf("%d ", exe->arg2->d_data);
		ft_printf("r%d", (short)(exe->arg3->d_value));
		ft_putchar('\n');
	}
	print_exe_opts(arena, exe);
	exe->process->carry = result ? 0 : 1;
	return (1);
}
