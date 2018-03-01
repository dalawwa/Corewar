#include "corewar.h"

int		set_name(t_bdd **bdd)
{
	int	i;

	i = 0;
	bdd[0]->name = addstr("live");
	bdd[1]->name = addstr("ld");
	bdd[2]->name = addstr("st");
	bdd[3]->name = addstr("add");
	bdd[4]->name = addstr("sub");
	bdd[5]->name = addstr("and");
	bdd[6]->name = addstr("or");
	bdd[7]->name = addstr("xor");
	bdd[8]->name = addstr("zjmp");
	bdd[9]->name = addstr("ldi");
	bdd[10]->name = addstr("sti");
	bdd[11]->name = addstr("fork");
	bdd[12]->name = addstr("lld");
	bdd[13]->name = addstr("lldi");
	bdd[14]->name = addstr("lfork");
	bdd[15]->name = addstr("aff");
	while (i < 16)
	{
		if (bdd[i]->name == NULL)
			return (perror_int("Error ", 0));
		i++;
	}
	return (1);
}

void		set_cycle(t_bdd *bdd_i, int i)
{
	if (i == 0 || i == 3 || i == 4 || i == 12)
		bdd_i->nb_cycle = 10;
	else if (i == 1 || i == 2)
		bdd_i->nb_cycle = 5;
	else if (i == 5 || i == 6 || i == 7)
		bdd_i->nb_cycle = 6;
	else if (i == 8)
		bdd_i->nb_cycle = 20;
	else if (i == 10 || i == 9)
		bdd_i->nb_cycle = 25;
	else if (i == 11)
		bdd_i->nb_cycle = 800;
	else if (i == 13)
		bdd_i->nb_cycle = 50;
	else if (i == 14)
		bdd_i->nb_cycle = 1000;
	else
		bdd_i->nb_cycle = 2;
}

int		set_meaning(t_bdd **bdd)
{
	int	i;

	i = 0;
	bdd[0]->meaning = addstr("alive");
	bdd[1]->meaning = addstr("load");
	bdd[2]->meaning = addstr("store");
	bdd[3]->meaning = addstr("addition");
	bdd[4]->meaning = addstr("soustraction");
	bdd[5]->meaning = addstr("et (and  r1, r2, r3   r1&r2 -> r3");
	bdd[6]->meaning = addstr("ou  (or   r1, r2, r3   r1 | r2 -> r3");
	bdd[7]->meaning = addstr("ou (xor  r1, r2, r3   r1^r2 -> r3");
	bdd[8]->meaning = addstr("jump if zero");
	bdd[9]->meaning = addstr("load index");
	bdd[10]->meaning = addstr("store index");
	bdd[11]->meaning = addstr("fork");
	bdd[12]->meaning = addstr("long load");
	bdd[13]->meaning = addstr("long load index");
	bdd[14]->meaning = addstr("long fork");
	bdd[15]->meaning = addstr("aff");
	while (i < 16)
	{
		if (bdd[i]->meaning == NULL)
			return (perror_int("Error ", 0));
		i++;
	}
	return (1);
}

void		set_nb_args(t_bdd *bdd_i, int i)
{
	if (i == 0 || i == 8 || i == 11 || i == 14 || i == 15)
		bdd_i->nb_args = 1;
	else if (i == 1 || i == 2 || i == 12)
		bdd_i->nb_args = 2;
	else
		bdd_i->nb_args = 3;
}

int		create_bdd(t_arena *arena)
{
	int	i;

	i = 0;
	arena->bdd = (t_bdd**)malloc(sizeof(t_bdd*) * 16);
	if (arena->bdd == NULL)
		return (0);
	while (i < 16)
	{
		arena->bdd[i] = (t_bdd*)malloc(sizeof(t_bdd));
		if (arena->bdd[i] == NULL)
			return (perror_int("Error ", 0));
		set_cycle(arena->bdd[i], i);
		set_nb_args(arena->bdd[i], i);
		arena->bdd[i]->opcode = i + 1; // comment mettre l'opcode ?
		if (i == 0 || i == 8 || i == 11 || i == 14)
			arena->bdd[i]->has_ocp = 0;
		else
			arena->bdd[i]->has_ocp = 1;
		i++;
	}
	set_name(arena->bdd);
	set_meaning(arena->bdd);
	if (set_bdd_ocp(arena) == 0)
		return (0);
	if (arena->opts->has_b == 1)
		print_bdd(arena);
	return (1);
}
