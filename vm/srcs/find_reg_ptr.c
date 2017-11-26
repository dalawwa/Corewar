#include "corewar.h"

char	*find_reg_ptr(char arg_value, t_exe *exe)
{
	int i;

	i = 1;
	while (i != (int)arg_value)
		i++;
	return (&exe->process->reg[i]);
}
