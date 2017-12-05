#include "corewar.h"

unsigned char	find_char_at_mem_pc_adv(int pc, int adv, t_arena *arena)
{
	int	i;

	i = 0;
	if (adv == 0)
		return (arena->mem[pc]);
	else if (adv > 0)
	{
		while (i < adv)
		{
			if (pc  == MEM_SIZE)
				pc = 0;
			pc++;
			i++;
		}
	}
	else if (adv < 0)
	{
		while (i > adv)
		{
			if (pc == 0)
				pc = MEM_SIZE;
			pc--;
			i--;
		}
	}
	return (arena->mem[pc]);
}
