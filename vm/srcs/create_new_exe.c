#include "corewar.h"

int		find_bdd_op(t_exe *exe_op, t_bdd **bdd)
{
	int	i;

	i = 0;
	while (i < 17)
	{
		if (exe_op->opcode == bdd[i]->opcode)
		{
			exe_op->bdd_op = bdd[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int			find_struct_ocp(t_exe *exe_op, t_bdd *bdd_op)
{
	int	i;

	i = 0;
	if (bdd_op->has_ocp == 0)
	{
		exe_op->ocp_op = bdd_op->ocp[0];
		return (1);
	}
	while (i < bdd_op->nb_ocp)
	{
		if (exe_op->ocp == bdd_op->ocp[i]->ocp)
			exe_op->ocp_op = bdd_op->ocp[i];
		i++;
	}
	return (1);
}

int		set_arg_x_value(t_arg *arg, int arg_num, t_arena *arena, t_proc *process)
{
	int	i;

	i = 0;
	if (arg_num == 1)
	{
		arg->type = process->exe_op->ocp_op->type_arg1;
		arg->size = process->exe_op->ocp_op->size_arg1;
		arg->value = (unsigned char *)malloc(sizeof(unsigned char) * arg->size);
		if (arg->value == NULL)
			return (perror_int("Error ", 0));
		while (i < process->exe_op->ocp_op->size_arg1)
		{
			arg->value[i] = arena->mem[process->pc + i];
			i++;
		}
		arg->d_value = a_hexa_to_i(arg->value, process->exe_op->ocp_op->size_arg1);
	}
	else if (arg_num == 2)
	{
		arg->type = process->exe_op->ocp_op->type_arg2;
		arg->size = process->exe_op->ocp_op->size_arg2;
		arg->value = (unsigned char *)malloc(sizeof(unsigned char) * process->exe_op->ocp_op->size_arg2);
		if (arg->value == NULL)
			return (perror_int("Error ", 0));
		while (i < process->exe_op->ocp_op->size_arg2)
		{
			arg->value[i] = arena->mem[process->pc + i];
			i++;
		}
		arg->d_value = a_hexa_to_i(arg->value, process->exe_op->ocp_op->size_arg2);
	}
	else
	{
		arg->type = process->exe_op->ocp_op->type_arg3;
		arg->size = process->exe_op->ocp_op->size_arg3;
		arg->value = (unsigned char *)malloc(sizeof(unsigned char) * process->exe_op->ocp_op->size_arg3);
		if (arg->value == NULL)
			return (perror_int("Error ", 0));
		while (i < process->exe_op->ocp_op->size_arg3)
		{
			arg->value[i] = arena->mem[process->pc + i];
			i++;
		}
		arg->d_value = a_hexa_to_i(arg->value, process->exe_op->ocp_op->size_arg3);
	}
	process->pc += i;
	return (1);
}

int			set_data(t_arg *arg, t_arena *arena, t_proc *process)
{
	if (arg->type == 'r')
	{
		arg->d_data = (int)process->reg[arg->d_value];
		arg->data = ft_unsi_strdup(process->reg[arg->d_value], 2);
	}
	else if (arg->type == 'd')
	{
		arg->data = ft_unsi_strdup(arg->data, arg->size);
		arg->d_data = arg->d_value;
	}
	else if (arg->type == 'i')
	{
		arg->data = malloc(sizeof(unsigned char) * 1);
		if (arg->data == NULL)
			return (perror_int("Error ", 0));
		arg->data[0] = arena->mem[arg->d_value];
		arg->d_data = a_hexa_to_i(arg->data, 1);
	}
	else
	{
		arg->data = 0;
		arg->d_data = 0;
	}
	return (1);
}

int			set_args_values(t_proc *process, t_arena *arena)
{
	int	ret;

	ret = 0;
	process->exe_op->arg1 = (t_arg *)malloc(sizeof(t_arg));
	if (process->exe_op->arg1 == NULL)
		return (perror_int("Error ", 0));
	set_arg_x_value(process->exe_op->arg1, 1, arena, process); 
	if (set_data(process->exe_op->arg1, arena, process) == 0)
		return (0);
	if (process->exe_op->bdd_op->nb_args > 1)
	{
		process->exe_op->arg2 = (t_arg *)malloc(sizeof(t_arg));
		if (process->exe_op->arg2 == NULL)
			return (perror_int("Error ", 0));
		set_arg_x_value(process->exe_op->arg2, 2, arena, process); 
		if (set_data(process->exe_op->arg1, arena, process) == 0)
			return (0);
	}
	if (process->exe_op->bdd_op->nb_args == 3)
	{
		process->exe_op->arg3 = (t_arg *)malloc(sizeof(t_arg));
		if (process->exe_op->arg3 == NULL)
			return (perror_int("Error ", 0));
		set_arg_x_value(process->exe_op->arg3, 3, arena, process); 
		if (set_data(process->exe_op->arg1, arena, process) == 0)
			return (0);
	}
	return (1);
}


void		init_exe(t_exe *exe_op)
{
	exe_op->opcode = 0;
	exe_op->ocp = 0;
	exe_op->arg1 = NULL;
	exe_op->arg2 = NULL;
	exe_op->arg3 = NULL;
	exe_op->to_wait = 0;
}

int		create_new_exe(t_arena *arena, t_proc *process, t_proc *parent)
{
	process->exe_op = (t_exe *)malloc(sizeof(t_exe));
	if (process->exe_op == NULL)
		return (perror_int("Error ", 0));
	init_exe(process->exe_op);
	process->exe_op->opcode = arena->mem[process->pc];
	process->pc++;
	find_bdd_op(process->exe_op, arena->bdd);
	if (process->exe_op->bdd_op->has_ocp == 1)
	{
		process->pc++;
		process->exe_op->ocp = arena->mem[process->pc];
	}
	find_struct_ocp(process->exe_op, process->exe_op->bdd_op);
	if (parent != NULL)
		process->exe_op->to_wait = process->exe_op->bdd_op->nb_cycle + parent->exe_op->to_wait;
	else
		process->exe_op->to_wait = process->exe_op->bdd_op->nb_cycle;
	if (set_args_values(process, arena) == 0)
		return (0);
	process->pc -= process->exe_op->ocp_op->size_adv;
	return (1);
}

/* REMARQUES & TODOs
 *
 * LE PC avance lors de la creation de l'EXE : Attention si PC == MEM_SIZE
 * DATA --> en char ou char * --> Attention Limit
 * la Value et la data d'un arg en INT non geree (cas ou size > 1) --> done
 */
