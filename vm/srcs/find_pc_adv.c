#include "corewar.h"

int		find_pc_adv(int pc, int adv, int stop)
{
	int	i;
	int	pc_tmp;
	int	adv_tmp;

	i = 0;
	pc_tmp = 0;
	adv_tmp = 0;
	if (stop == 0)
	{
//		ft_printf("\nSTOP = 0 | FIRST pc_tmp = %d\n", pc_tmp);
		if (adv < 0x8000)
		{
			pc_tmp = pc + (adv % IDX_MOD);
//			ft_printf("inf NEXT  pc_tmp = %d\n", pc_tmp);
			if (pc_tmp >= MEM_SIZE)
				pc_tmp = pc_tmp - MEM_SIZE;
		}
		else
		{
			adv_tmp = IDX_MOD - (adv % IDX_MOD);
			if (adv_tmp == 512)
				adv_tmp = 0;
			pc_tmp = pc - adv_tmp;
//			ft_printf("sup NEXT  pc_tmp = %d\n", pc_tmp);
			if (pc_tmp < 0)
				pc_tmp = MEM_SIZE + pc_tmp;
		}
	}
	else
	{
//		ft_printf("\nSTOP = 1 | FIRST pc_tmp = %d\n", pc_tmp);
		if (adv < 0x8000 && adv >= 0)
		{
			pc_tmp = pc + (adv % IDX_MOD);
//			ft_printf("adv = %d\ninf NEXT  pc_tmp = %d\n", adv,  pc_tmp);
			if (pc_tmp >= MEM_SIZE)
			{
//	ft_printf("\npc_tmp: %d\n", pc_tmp);
				return (0);
			}
		}
		else if (adv >= 0x8000)
		{
			adv_tmp = IDX_MOD - (adv % IDX_MOD);
			if (adv_tmp == 512)
				adv_tmp = 0;
			pc_tmp = pc - adv_tmp;
//			ft_printf("sup NEXT  pc_tmp = %d\n", pc_tmp);
			if (pc_tmp < 0)
			{
//				ft_printf("\nfpa pc_tmp < 0\n");
//	ft_printf("\npc_tmp: %d\n", pc_tmp);
				return (0);
			}
		}
		else
		{
			pc_tmp = pc;
			while (i > adv)
			{
//				ft_printf("pc_tmp = %d\n", pc_tmp);
				if (pc_tmp == 0)
					pc_tmp = MEM_SIZE;
				pc_tmp--;
				i--;
			}
		}
	}

//		if (pc_tmp > IDX_MOD)
//			pc_tmp = pc;
//		ft_printf("END   pc_tmp = %d\n", pc_tmp);
/*		pc_tmp = ((pc + adv) % IDX_MOD);
	ft_printf("FIRST pc_tmp = %d\n", pc_tmp);
		if (pc_tmp > IDX_MOD / 2)
			pc_tmp = pc_tmp - IDX_MOD;
	ft_printf("NEXT  pc_tmp = %d\n", pc_tmp);*/
//	ft_printf("\npc_tmp: %d\n", pc_tmp);
		return (pc_tmp);
}
		/*
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
//					ft_printf("\nBOYA\n");
					return (0);
				}
			}
			pc_tmp++;
			i++;
			if (pc_tmp == MEM_SIZE && i == adv)
			{
//				ft_printf("HAHA - End PC = %d\n", 0);
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
	ft_printf("__EOfind_pc_adv_last - End PC = %d\n", pc_tmp);
	return (pc_tmp);
}
*/
