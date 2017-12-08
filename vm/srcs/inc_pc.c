#include "corewar.h"

int		inc_pc(t_proc *process, int adv)
{
	int	i;

	i = 0;
//	ft_printf("Process %d : ", process->process_num);
//	if (process->exe_op != NULL)
//		ft_printf("EXE = %.2x", process->exe_op->bdd_op->opcode);
//	ft_printf("Adv = %d --> Start PC = %d", adv, process->pc);
	if (adv > 0)
	{
		while (i < adv)
		{
			if (process->pc == MEM_SIZE - 1)
			{
				process->pc = 0;
				return (1);
			}
			process->pc++;
			i++;
		}
	}
	if (adv < 0)
	{
		while (i > adv)
		{
			if (process->pc == 0)
				process->pc = MEM_SIZE - 1;
			process->pc--;
			i--;
		}
	}
//	ft_printf(" - End PC = %d\n", process->pc);
	return (process->pc);
}
