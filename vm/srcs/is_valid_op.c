#include "corewar.h"

int		is_valid_op(t_arena *arena, t_proc *proc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < NB_OP)
	{
		if (arena->bdd[i]->opcode == arena->mem[proc->pc])
		{
			if (arena->bdd[i]->has_ocp == 1)
			{
				while (j < arena->bdd[i]->nb_ocp)
				{
					if (arena->bdd[i]->ocp[j]->ocp == arena->mem[proc->pc + 1])
						return (1);
					j++;
				}
				return (0);
			}
			return (1);
		}
		i++;
	}
	return (0);
}
