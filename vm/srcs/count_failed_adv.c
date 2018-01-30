#include "corewar.h"

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

int		get_size_by_param_type(int type, t_exe *exe)
{
	int res;

	res = 0;
	if (type == 0b10)
	{
		/* difference entre exe qui prennent les directs sur 2 octets et les autres */
		if (exe->opcode == 0x9 || exe->opcode == 0xa || exe->opcode == 0xb || exe->opcode == 0xc || exe->opcode == 0xe || exe->opcode == 0xf)
			res = 2;
		else
			res = 4;
	}
	if (type == 0b01)
		res = 1;
	if (type == 0b11)
		res = 2;
	return (res);
}

int		get_size_from_ocp(char c, t_exe *exe)
{
	int	first;
	int	sec;
	int third;

	first = c >> 6;
	sec = c >> 4 & 0b0011;
	third = c >> 2 & 0b000011;
	if (exe->bdd_op->nb_args == 2)
		return (get_size_by_param_type(first, exe) + get_size_by_param_type(sec, exe));
	else if (exe->bdd_op->nb_args == 3)
		return (get_size_by_param_type(first, exe) + get_size_by_param_type(sec, exe) + get_size_by_param_type(third, exe));
	return (NB_OP);
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
			return (handle_two_opcode(arena->mem[exe->process->pc], arena->bdd[i]->opcode));
		i++;
	}
	return (2 + get_size_from_ocp(exe->ocp, exe));
}
