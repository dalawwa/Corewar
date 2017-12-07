#include "corewar.h"

int		find_pc_adv(t_proc *process, int adv)
{
	int	i;
	int	pc_tmp;

	i = 0;
	pc_tmp = process->pc;
//	ft_printf("Process %d : ", process->process_num);
//	if (process->exe_op != NULL)
//		ft_printf("EXE = %.2x", process->exe_op->bdd_op->opcode);
//	ft_printf("Adv = %d --> Start PC = %d", adv, process->pc);
	if (adv > 0)
	{
		while (i < adv)
		{
			if (pc_tmp == MEM_SIZE - 1)
			{
				pc_tmp = 0;
				return (1);
			}
			pc_tmp++;
			i++;
		}
	}
	if (adv < 0)
	{
		while (i > adv)
		{
			if (pc_tmp == 0)
				pc_tmp = MEM_SIZE - 1;
			pc_tmp--;
			i--;
		}
	}
//	ft_printf(" - End PC = %d\n", process->pc);
	return (pc_tmp);
}
