#include "corewar.h"

int		set_args_type4(t_bdd *bdd_i, int i)
{
	if (i == 10)
	{
		bdd_i->ocp[1]->type_arg1 = 'r';
		bdd_i->ocp[1]->type_arg2 = 'r';
		bdd_i->ocp[1]->type_arg3 = 'd';
		bdd_i->ocp[2]->type_arg1 = 'r';
		bdd_i->ocp[2]->type_arg2 = 'd';
		bdd_i->ocp[2]->type_arg3 = 'd';
		bdd_i->ocp[3]->type_arg1 = 'r';
		bdd_i->ocp[3]->type_arg2 = 'd';
		bdd_i->ocp[3]->type_arg3 = 'r';
		bdd_i->ocp[4]->type_arg1 = 'r';
		bdd_i->ocp[4]->type_arg2 = 'i';
		bdd_i->ocp[4]->type_arg3 = 'd';
		bdd_i->ocp[5]->type_arg1 = 'r';
		bdd_i->ocp[5]->type_arg2 = 'i';
		bdd_i->ocp[5]->type_arg3 = 'r';
	}
	else if (i == 15)
		bdd_i->ocp[0]->type_arg1 = 'r';
	else if (i == 0 || i == 8 || i == 14 || i == 11)
		bdd_i->ocp[0]->type_arg1 = 'd';
	return (1);
}

int		set_args_type3(t_bdd *bdd_i, int i)
{
	if (i == 9 || i == 13)
	{
		bdd_i->ocp[1]->type_arg1 = 'r';
		bdd_i->ocp[1]->type_arg2 = 'd';
		bdd_i->ocp[1]->type_arg3 = 'r';
		bdd_i->ocp[2]->type_arg1 = 'd';
		bdd_i->ocp[2]->type_arg2 = 'r';
		bdd_i->ocp[2]->type_arg3 = 'r';
		bdd_i->ocp[3]->type_arg1 = 'd';
		bdd_i->ocp[3]->type_arg2 = 'd';
		bdd_i->ocp[3]->type_arg3 = 'r';
		bdd_i->ocp[4]->type_arg1 = 'i';
		bdd_i->ocp[4]->type_arg2 = 'r';
		bdd_i->ocp[4]->type_arg3 = 'r';
		bdd_i->ocp[5]->type_arg1 = 'i';
		bdd_i->ocp[5]->type_arg2 = 'd';
		bdd_i->ocp[5]->type_arg3 = 'r';
	}
	return (set_args_type4(bdd_i, i));
}


int		set_args_type2(t_bdd *bdd_i, int i)
{
	if (i >= 5 && i <= 7)
	{
		bdd_i->ocp[1]->type_arg1 = 'r';
		bdd_i->ocp[1]->type_arg2 = 'd';
		bdd_i->ocp[1]->type_arg3 = 'r';
		bdd_i->ocp[2]->type_arg1 = 'r';
		bdd_i->ocp[2]->type_arg2 = 'i';
		bdd_i->ocp[2]->type_arg3 = 'r';
		bdd_i->ocp[3]->type_arg1 = 'd';
		bdd_i->ocp[3]->type_arg2 = 'd';
		bdd_i->ocp[3]->type_arg3 = 'r';
		bdd_i->ocp[4]->type_arg1 = 'd';
		bdd_i->ocp[4]->type_arg2 = 'i';
		bdd_i->ocp[4]->type_arg3 = 'r';
		bdd_i->ocp[5]->type_arg1 = 'i';
		bdd_i->ocp[5]->type_arg2 = 'd';
		bdd_i->ocp[5]->type_arg3 = 'r';
		bdd_i->ocp[6]->type_arg1 = 'i';
		bdd_i->ocp[6]->type_arg2 = 'i';
		bdd_i->ocp[6]->type_arg3 = 'r';
		bdd_i->ocp[7]->type_arg1 = 'd';
		bdd_i->ocp[7]->type_arg2 = 'r';
		bdd_i->ocp[7]->type_arg3 = 'r';
		bdd_i->ocp[8]->type_arg1 = 'i';
		bdd_i->ocp[8]->type_arg2 = 'r';
		bdd_i->ocp[8]->type_arg3 = 'r';
	}
	return (set_args_type3(bdd_i, i));
}

int		set_args_type(t_bdd *bdd_i, int i)
{
	if (i == 1 || i == 12)
	{
		bdd_i->ocp[0]->type_arg1 = 'd';
		bdd_i->ocp[1]->type_arg1 = 'i';
		bdd_i->ocp[0]->type_arg2 = 'r';
		bdd_i->ocp[1]->type_arg2 = 'r';
	}
	else if (i == 2)
	{
		bdd_i->ocp[0]->type_arg1 = 'r';
		bdd_i->ocp[0]->type_arg2 = 'r';
		bdd_i->ocp[1]->type_arg1 = 'r';
		bdd_i->ocp[1]->type_arg2 = 'i';
	}
	else if ((i >= 3 && i <= 7) || i == 9 || i == 10 || i == 13)
	{
		bdd_i->ocp[0]->type_arg1 = 'r';
		bdd_i->ocp[0]->type_arg2 = 'r';
		bdd_i->ocp[0]->type_arg3 = 'r';
		
	}
	if (i == 1 || i == 2 || i == 12)
		return (1);
	return (set_args_type2(bdd_i, i));
}

void	set_ptr_op(t_bdd *bdd_i, int i)
{
	int	j;

	j = 0;
	if (i == 0)
		bdd_i->ocp[j]->fct = &op_live;
	else if (i == 1)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_ld;
			j++;
		}
	}
	else if (i == 2)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_st;
			j++;
		}
	}
	else if (i == 3)
		bdd_i->ocp[j]->fct = &op_add;
	else if (i == 4)
		bdd_i->ocp[j]->fct = &op_sub;
	else if (i == 5)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_and;
			j++;
		}
	}
	else if (i == 6)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_or;
			j++;
		}
	}
	else if (i == 7)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_xor;
			j++;
		}
	}
	else if (i == 8)
		bdd_i->ocp[j]->fct = &op_zjmp;
	else if (i == 9)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_ldi;
			j++;
		}
	}
	else if (i == 10)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_sti;
			j++;
		}
	}
	else if (i == 11)
		bdd_i->ocp[j]->fct = &op_fork;
	else if (i == 12)
	{
		while (j < bdd_i->nb_ocp)
		{
			bdd_i->ocp[j]->fct = &op_lld;
			j++;
		}
	}
	else if (i == 14)
		bdd_i->ocp[j]->fct = &op_lfork;
	else if (i == 15)
		bdd_i->ocp[j]->fct = &op_aff;
}

int		create_ocp(t_bdd *bdd_i, int i)
{
	int	j;

	j = 0;
	if (i == 1 || i == 2 || i == 12)
		bdd_i->nb_ocp = 2;
	else if (i == 5 || i == 6 || i == 7)
		bdd_i->nb_ocp = 9;
	else if (i == 9 || i == 10 || i == 13)
		bdd_i->nb_ocp = 6;
	else
		bdd_i->nb_ocp = 1;
	bdd_i->ocp = (t_ocp**)malloc(sizeof(t_ocp*) * bdd_i->nb_ocp);
	if (bdd_i->ocp == NULL)
		return (perror_int("Error ", 0));
	while (j < bdd_i->nb_ocp)
	{
		bdd_i->ocp[j] = (t_ocp*)malloc(sizeof(t_ocp));
		if (bdd_i->ocp[j] == NULL)
			return (perror_int("Error ", 0));
		bdd_i->ocp[j]->type_arg1 = '\0';
		bdd_i->ocp[j]->type_arg2 = '\0';
		bdd_i->ocp[j]->type_arg3 = '\0';
		j++;
	}
	set_args_type(bdd_i, i);
	return (1);
}

int		set_bdd_ocp(t_arena *arena)
{
	int	i;

	i = 0;
	while (i < NB_OP)
	{
		arena->bdd[i]->nb_ocp = 0;
		create_ocp(arena->bdd[i], i);
		if (arena->bdd[i]->ocp == NULL)
			return (0);
		i++;
	}
	set_ocp_and_size(arena->bdd);
	i = 0;
	while (i < NB_OP)
	{
		set_ptr_op(arena->bdd[i], i);
		i++;
	}
	return (1);
}
