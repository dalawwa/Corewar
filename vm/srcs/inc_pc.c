#include "corewar.h"

int		inc_pc(t_proc *process, int adv)
{
//	process->pc = find_pc_adv(process->pc, adv, 1);
	process->pc = get_adv(process->pc + adv);
	return (1);
/*
	int	i;
	short int neg;

	i = 0;
	neg = (short int)adv;

//	ft_printf("Process %d : ", process->process_num);
//	if (process->exe_op != NULL)
//		ft_printf("EXE = %.2x", process->exe_op->bdd_op->opcode);
//	ft_printf("Adv = %hd --> Start PC = %d", (short int)adv, process->pc);
	if ((short int)adv >= 0)
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
	else
	{
		while (i > neg)
		{
			if (process->pc == 0)
				process->pc = MEM_SIZE;
			process->pc--;
			i--;
		}
//	ft_printf(" - End PC = %d\n", process->pc);
	}
//	ft_printf(" - End PC = %d\n", process->pc);
	return (process->pc);*/
}
