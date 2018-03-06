#include "corewar.h"

int		op_sub(t_arena *arena, t_exe *exe)
{
	unsigned int	result;
	unsigned char	*s;

//	arena = arena + 0;
	print_add_sub(arena, exe);
	print_exe_opts(arena, exe);
	result = exe->arg1->d_data - exe->arg2->d_data;
//	ft_printf("Result = %d\n", result);
	if (result > 0xffffffff)
	{
		ft_putendl("op_add FAILED");
		exe->process->carry = 0;
		return (0);
	}
	s = ft_ito_hexa(result);
	if (s == NULL)
		return (-1);
	exe->process->reg[exe->arg3->d_value][0] = s[0];
	exe->process->reg[exe->arg3->d_value][1] = s[1];
	exe->process->reg[exe->arg3->d_value][2] = s[2];
	exe->process->reg[exe->arg3->d_value][3] = s[3];
	free(s);
	s = NULL;
//	ft_printf("carry Before %d\n", exe->process->carry);
	exe->process->carry = result ? 0 : 1;
//	ft_printf("carry After  %d\n", exe->process->carry);
//	is_carry_to_modify(exe);
	return (1);
}
