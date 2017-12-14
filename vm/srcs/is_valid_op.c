#include "corewar.h"

int		is_valid_op(t_arena *arena, t_proc *proc)
{
	int	i;
//	int	j;

	i = 0;
//	j = 0;
	while (i < NB_OP)
	{
//		ft_printf("bdd[i]->opcode = %.2x - arena->mem[%d] = %.2x\n", arena->bdd[i]->opcode, proc->pc, arena->mem[proc->pc]);
		if (arena->bdd[i]->opcode == arena->mem[proc->pc])
		{
//			ft_printf("OP found : %s\n", arena->bdd[i]->name);
/*			if (arena->bdd[i]->has_ocp == 1)
			{
//				ft_printf("has_ocp == 1\n");
				while (j < arena->bdd[i]->nb_ocp)
				{
//					ft_printf("ocp[%d]->ocp = %.2x - mem[pc + 1] = %.2x\n", j, arena->bdd[i]->ocp[j]->ocp, arena->mem[proc->pc + 1]);
					if (arena->bdd[i]->ocp[j]->ocp == arena->mem[proc->pc + 1])
					{
//						ft_putendl("is a valid_process --> return 1");
						return (1);
					}
					j++;
				}
//				if (arena->opts->has_v && arena->opts->v >= 16)
//					ft_printf("ADV 2 (%#.4x -> %#.4x) %.2x %.2x\n", proc->pc, proc->pc + 2, arena->mem[proc->pc], arena->mem[proc->pc + 1]);
//				ft_putendl("is a valid_process --> return 0.0");
				return (1);
			}
//			ft_putendl("is a valid_process --> return 1");*/
			return (1);
		}
		i++;
	}
//	ft_putendl("is a valid_process --> return 0");
	return (0);
}
