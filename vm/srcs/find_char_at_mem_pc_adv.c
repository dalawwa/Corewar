#include "corewar.h"

unsigned char	find_char_at_mem_pc_adv(int pc, int adv, t_arena *arena)
{
	int	i;

	i = 0;
	return (arena->mem[get_adv(pc + adv)]);
}
