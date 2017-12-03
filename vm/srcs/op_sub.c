#include "corewar.h"

int		op_sub(t_arena *arena, t_exe *exe)
{
	int				result;
	unsigned char	*s;

	arena = arena + 0;
	result = exe->arg1->d_value - exe->arg2->d_value;
	if (result > 0xffff)
	{
		ft_putendl("op_sub FAILED");
		exe->process->carry = 0;
		return (0);
	}
	s = ft_ito_hexa(result);
	exe->process->reg[exe->arg3->d_value][0] = s[0];
	exe->process->reg[exe->arg3->d_value][1] = s[1];
	free(s);
	s = NULL;
	is_carry_to_modify(exe);
	return (1);
}
