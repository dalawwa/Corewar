#include "corewar.h"

int		find_pc_adv(int pc, int adv, int stop)
{
	int	i;
	int	pc_tmp;

	i = 0;
	pc_tmp = ((pc + adv) % IDX_MOD);
//	ft_printf("FIRST pc_tmp = %d\n", pc_tmp);
	if (pc_tmp > IDX_MOD / 2)
		pc_tmp = pc_tmp - IDX_MOD;
//	ft_printf("NEXT  pc_tmp = %d\n", pc_tmp);
	return (pc_tmp);
	pc_tmp = pc;
//	ft_printf("Process %d : ", process->process_num);
//	if (process->exe_op != NULL)
//		ft_printf("EXE = %.2x", process->exe_op->bdd_op->opcode);
//	ft_printf("MEM_ZISE = %d - Adv = %d --> Start PC = %d", MEM_SIZE, adv, pc);
	if (adv > 0)
	{
//		if (adv > 65536)
//			adv = 65536 - adv;
		while (i < adv)
		{
//			ft_printf("i = %d - pc_tmp = %d\n", i, pc_tmp);
			if (pc_tmp == MEM_SIZE)
			{
				if (stop == 0)
					pc_tmp = 0;
				else
				{
//					ft_printf(" - End PC = %d\n", 0);
					return (0);
				}
			}
			pc_tmp++;
			i++;
			if (pc_tmp == MEM_SIZE && i == adv)
			{
//				ft_printf(" - End PC = %d\n", 0);
				return (0);
			}
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
