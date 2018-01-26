#include "corewar.h"

int		get_adv_size(t_exe *exe, char ocp)
{
	char first;
	char second;
	char third;

	exe = exe + 0;
	first = ocp >> 6;
	second = (ocp >> 4) & 0b0011;
	third = (ocp >> 2) & 0b000011;
	return (first + second + third);
}

int		handle_two_opcode(unsigned char op1, unsigned char op2)
{
	if (op1 < 0x04 || op1 == 0x0d || op2 < 0x04)
		return (2);
	if (op2 < 0x08)
		return (3);
	if (op1 > 0x09 || op2 > 0x0b)
		return (4);
	return (6);
}


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
			return (handle_two_opcode(arena->mem[exe->process->pc], arena->bdd[i]->opcode));
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
