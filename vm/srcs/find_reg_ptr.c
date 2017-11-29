#include "corewar.h"

unsigned char	*find_reg_ptr(int arg_value, t_exe *exe)
{
	int i;

	i = 1;
	while (i != arg_value)
		i++;
	return (exe->process->reg[i]);
}
