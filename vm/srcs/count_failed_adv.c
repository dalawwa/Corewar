#include "corewar.h"

int		count_failed_adv(t_arena *arena, t_exe *exe)
{
	int	i;
	int	j;
	int	test;

	i = 0;
	j = 0;
	test = 0;
	arena = arena + 0;
	if (exe->size_failed_adv != 0)
		return (exe->size_failed_adv);
	while (i < NB_OP)
	{
		if (find_char_at_mem_pc_adv(exe->process->pc, 1, arena) == arena->bdd[i]->opcode)
		{
			if (arena->bdd[i]->has_ocp)
			{
				while (j < arena->bdd[i]->nb_ocp && arena->bdd[i]->ocp[j]->ocp != find_char_at_mem_pc_adv(exe->process->pc, 2, arena))
					j++;
				if (j == arena->bdd[i]->nb_ocp)
					return (3); // ou 2 peut etre ? si 2 op trouve mais pas bon opcode --> comme un seul opcode
				test = arena->bdd[i]->ocp[j]->size_adv + 1;
				while (find_char_at_mem_pc_adv(exe->process->pc + test, 1, arena) == 0 && test > 0)
				{
					test--;
				}
				return (test);
			}
			return (1 + arena->bdd[i]->ocp[j]->size_adv);
		}
		i++;
	}
	return (2);
}
