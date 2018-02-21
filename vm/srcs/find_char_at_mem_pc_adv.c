#include "corewar.h"

unsigned char	find_char_at_mem_pc_adv(int pc, int adv, t_arena *arena)
{
	int	i;

	i = 0;
	return (arena->mem[get_adv(pc + adv) % IDX_MOD]);
/*
	ft_printf("pc = %d - adv = %d", pc, adv);
	if (adv == 0)
		return (arena->mem[pc]);
	else if (adv > 0)
	{
		while (i < adv)
		{
			if (pc  == MEM_SIZE - 1)
				return (arena->mem[0]);
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
	ft_printf(" - New_pc = %d\n", pc);
	return (arena->mem[pc]);*/
}
