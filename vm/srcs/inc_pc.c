#include "corewar.h"

int		inc_pc(t_proc *process, int adv)
{
	process->pc = get_adv(process->pc + adv);
	return (1);
}
