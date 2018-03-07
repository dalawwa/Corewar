#include "corewar.h"

int     set_arg_3_value(t_arg *arg, t_arena *arena, t_proc *process)
{
    int	i;

	i = 0;
    arg->type = process->exe_op->ocp_op->type_arg3;
    arg->size = process->exe_op->ocp_op->size_arg3;
    arg->value = (unsigned char *)malloc(sizeof(unsigned char) * process->exe_op->ocp_op->size_arg3);
    if (arg->value == NULL)
        return (perror_int("Error ", 0));
    while (i < process->exe_op->ocp_op->size_arg3)
    {
        arg->value[i] = arena->mem[process->pc];
        inc_pc(process, 1);
        i++;
    }
    arg->d_value = a_hexa_to_i(arg->value, process->exe_op->ocp_op->size_arg3);
    return (1);
}

int     set_arg_2_value(t_arg *arg, t_arena *arena, t_proc *process)
{
    int	i;

	i = 0;
    arg->type = process->exe_op->ocp_op->type_arg2;
    arg->size = process->exe_op->ocp_op->size_arg2;
    arg->value = (unsigned char *)malloc(sizeof(unsigned char) * process->exe_op->ocp_op->size_arg2);
    if (arg->value == NULL)
        return (perror_int("Error ", 0));
    while (i < process->exe_op->ocp_op->size_arg2)
    {
        arg->value[i] = arena->mem[process->pc];
        inc_pc(process, 1);
        i++;
    }
    arg->d_value = a_hexa_to_i(arg->value, process->exe_op->ocp_op->size_arg2);
    return (1);
}

int		set_arg_1_value(t_arg *arg, t_arena *arena, t_proc *process)
{
	int	i;

	i = 0;
    arg->type = process->exe_op->ocp_op->type_arg1;
    arg->size = process->exe_op->ocp_op->size_arg1;
    arg->value = (unsigned char *)malloc(sizeof(unsigned char) * arg->size);
    if (arg->value == NULL)
        return (perror_int("Error ", 0));
    while (i < process->exe_op->ocp_op->size_arg1)
    {
        arg->value[i] = arena->mem[process->pc];
        inc_pc(process, 1);
        i++;
    }
    arg->d_value = a_hexa_to_i(arg->value, process->exe_op->ocp_op->size_arg1);
	return (1);
}

int     malloc_args(t_proc *process)
{
    process->exe_op->arg1 = (t_arg *)malloc(sizeof(t_arg));
	if (process->exe_op->arg1 == NULL)
		return (perror_int("Error ", 0));
    if (process->exe_op->bdd_op->nb_args > 1)
	{
		process->exe_op->arg2 = (t_arg *)malloc(sizeof(t_arg));
		if (process->exe_op->arg2 == NULL)
			return (perror_int("Error ", 0));
    }
    	if (process->exe_op->bdd_op->nb_args == 3)
	{
		process->exe_op->arg3 = (t_arg *)malloc(sizeof(t_arg));
		if (process->exe_op->arg3 == NULL)
			return (perror_int("Error ", 0));
    }
    return (1);
}

int		set_args_values(t_proc *process, t_arena *arena, int *i)
{
	if (malloc_args(process) == 0)
        return (0);
	set_arg_1_value(process->exe_op->arg1, arena, process);
	*i = *i + process->exe_op->ocp_op->size_arg1;
	if (set_data(process->exe_op->arg1, arena, process, *i) == 0)
		return (0);
	if (process->exe_op->bdd_op->nb_args > 1)
	{
		set_arg_2_value(process->exe_op->arg2, arena, process); 
		*i = *i + process->exe_op->ocp_op->size_arg2;
		if (set_data(process->exe_op->arg2, arena, process, *i) == 0)
			return (0);
	}
	if (process->exe_op->bdd_op->nb_args == 3)
	{
		set_arg_3_value(process->exe_op->arg3, arena, process); 
		*i = *i + process->exe_op->ocp_op->size_arg3;
		if (set_data(process->exe_op->arg3, arena, process, *i) == 0)
			return (0);
	}
	return (1);
}