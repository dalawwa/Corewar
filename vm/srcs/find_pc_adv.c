#include "corewar.h"

int		find_pc_adv(int pc, int adv, int stop)
{
	int	i;
	int	pc_tmp;

	i = 0;
	pc_tmp = pc;
//	ft_printf("Process %d : ", process->process_num);
//	if (process->exe_op != NULL)
//		ft_printf("EXE = %.2x", process->exe_op->bdd_op->opcode);
//	ft_printf("MEM_ZISE = %d - Adv = %d --> Start PC = %d\n", MEM_SIZE, adv, pc);
	if (adv > 0)
	{
		while (i < adv)
		{
//			ft_printf("i = %d - pc_tmp = %d\n", i, pc_tmp);
			if (pc_tmp == MEM_SIZE)
			{
				if (stop == 0)
					pc_tmp = 0;
				else
					return (0);
			}
			pc_tmp++;
			i++;
			if (pc_tmp == MEM_SIZE && i == adv)
				return (0);
//			ft_printf("OUT : i = %d - pc_tmp = %d\n", i, pc_tmp);
		}
	}
	else
	{
//		ft_putendl("\nadv < 0");
		while (i > adv)
		{
//			ft_printf("pc_tmp = %d\n", pc_tmp);
			if (pc_tmp == 0)
				pc_tmp = MEM_SIZE;
			pc_tmp--;
			i--;
		}
	}
//	ft_printf(" - End PC = %d\n", pc_tmp);
	return (pc_tmp);
}
