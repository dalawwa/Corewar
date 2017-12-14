#include "corewar.h"


int		is_failed_reg_nbr(t_exe *exe, t_arg *arg)
{
	if (arg && arg->type == 'r' && arg->d_value > REG_NUMBER)
	{
		if (exe->arg1)
			free_arg(exe->arg1);
		if (exe->arg2)
			free_arg(exe->arg2);
		if (exe->arg3)
			free_arg(exe->arg3);
		exe->size_failed_adv = exe->ocp_op->size_adv;
		exe->ocp_op = NULL;
		return (1);
	}
	return (0);
}

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
//		ft_printf("exe->ocp = %.2x - bbd->ocp[%d] = %.2x\n", exe_op->ocp, i, bdd_op->ocp[i]->ocp);
		if (exe_op->ocp == bdd_op->ocp[i]->ocp)
		{
			exe_op->ocp_op = bdd_op->ocp[i];
			return (1);
		}
		i++;
	}
	exe_op->ocp_op = NULL;
//	ft_putendl("no STRUCT OCP FOUND");
	return (0);
}

int		set_arg_x_value(t_arg *arg, int arg_num, t_arena *arena, t_proc *process)
{
	int	i;

	i = 0;
//	if (process->exe_op->bdd_op->opcode == 10)
//		ft_printf("______________EXE : arg num %d\n", arg_num);
	if (arg_num == 1)
	{
		arg->type = process->exe_op->ocp_op->type_arg1;
		arg->size = process->exe_op->ocp_op->size_arg1;
		arg->value = (unsigned char *)malloc(sizeof(unsigned char) * arg->size);
		if (arg->value == NULL)
			return (perror_int("Error ", 0));
//		ft_putendl("ARG 1");
		while (i < process->exe_op->ocp_op->size_arg1)
		{
			arg->value[i] = arena->mem[process->pc];
			inc_pc(process, 1);
			i++;
		}
		arg->d_value = a_hexa_to_i(arg->value, process->exe_op->ocp_op->size_arg1);
	}
	else if (arg_num == 2)
	{
//		ft_putendl("ARG 2");
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
	}
	else
	{
//		ft_putendl("ARG 3");
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
	}
	return (1);
}

int			set_data(t_arg *arg, t_arena *arena, t_proc *process, int i)
{
//	ft_printf("arg Type = %c\n", arg->type);
	if (arg->type == 'r')
	{
		arg->d_data = a_hexa_to_i(process->reg[arg->d_value], 4);
		arg->data = ft_unsi_strdup(process->reg[arg->d_value], 4);
	}
	else if (arg->type == 'd')
	{
		arg->data = ft_unsi_strdup(arg->value, arg->size);
		arg->d_data = arg->d_value;
	}
	else if (arg->type == 'i')
	{
		arg->data = malloc(sizeof(unsigned char) * 4);
		if (arg->data == NULL)
			return (perror_int("Error ", 0));
		arg->data[0] = find_char_at_mem_pc_adv(process->pc, -i + arg->d_value, arena);
		arg->data[1] = find_char_at_mem_pc_adv(process->pc, -i + arg->d_value + 1, arena);
		arg->data[2] = find_char_at_mem_pc_adv(process->pc, -i + arg->d_value + 2, arena);
		arg->data[3] = find_char_at_mem_pc_adv(process->pc, -i + arg->d_value + 3, arena);
//		arg->data[1] = arena->mem[process->pc - i + arg->d_value + 1];
//		arg->data[2] = arena->mem[process->pc - i + arg->d_value + 2];
//		arg->data[3] = arena->mem[process->pc - i + arg->d_value + 3];
		arg->d_data = a_hexa_to_i(arg->data, 4);
	}
	else
	{
		arg->data = 0;
		arg->d_data = 0;
	}
	return (1);
}

int			set_args_values(t_proc *process, t_arena *arena, int *i)
{
	int	ret;

	ret = 0;
	process->exe_op->arg1 = (t_arg *)malloc(sizeof(t_arg));
	if (process->exe_op->arg1 == NULL)
		return (perror_int("Error ", 0));
	set_arg_x_value(process->exe_op->arg1, 1, arena, process);
	*i = *i + process->exe_op->ocp_op->size_arg1;
//	ft_printf("arg1->d_value = %d\n", process->exe_op->arg1->d_value);
	if (set_data(process->exe_op->arg1, arena, process, *i) == 0)
		return (0);
	if (process->exe_op->bdd_op->nb_args > 1)
	{
		process->exe_op->arg2 = (t_arg *)malloc(sizeof(t_arg));
		if (process->exe_op->arg2 == NULL)
			return (perror_int("Error ", 0));
		set_arg_x_value(process->exe_op->arg2, 2, arena, process); 
		*i = *i + process->exe_op->ocp_op->size_arg2;
		if (set_data(process->exe_op->arg2, arena, process, *i) == 0)
			return (0);
	}
	if (process->exe_op->bdd_op->nb_args == 3)
	{
		process->exe_op->arg3 = (t_arg *)malloc(sizeof(t_arg));
		if (process->exe_op->arg3 == NULL)
			return (perror_int("Error ", 0));
		set_arg_x_value(process->exe_op->arg3, 3, arena, process); 
		*i = *i + process->exe_op->ocp_op->size_arg3;
		if (set_data(process->exe_op->arg3, arena, process, *i) == 0)
			return (0);
	}
	return (1);
}


void		init_exe(t_exe *exe_op, t_proc *process)
{
	exe_op->opcode = 0;
	exe_op->ocp = 0;
	exe_op->arg1 = NULL;
	exe_op->arg2 = NULL;
	exe_op->arg3 = NULL;
	exe_op->to_wait = 0;
	exe_op->size_failed_adv = 0;
	exe_op->process = process;
}

int		create_new_exe(t_arena *arena, t_proc *process, t_proc *parent)
{
//	ft_printf("\n--------------------->  NEW EXE in Creation from Process %d\n", process->process_num);
	int	i;

	i = 0;
	process->exe_op = (t_exe *)malloc(sizeof(t_exe));
	if (process->exe_op == NULL)
		return (perror_int("Error ", 0));
	init_exe(process->exe_op, process);
	process->exe_op->opcode = arena->mem[process->pc];
	inc_pc(process, 1);
//	process->pc++;
	i++;
	find_bdd_op(process->exe_op, arena->bdd);
	if (process->exe_op->bdd_op->has_ocp == 1)
	{
		process->exe_op->ocp = arena->mem[process->pc];
		inc_pc(process, 1);
//		process->pc++;
		i++;
	}
	if (parent != NULL)
		process->exe_op->to_wait = process->exe_op->bdd_op->nb_cycle;
	else
		process->exe_op->to_wait = process->exe_op->bdd_op->nb_cycle;
	if (find_struct_ocp(process->exe_op, process->exe_op->bdd_op) == 0)
	{
		inc_pc(process, -i);
//		ft_putendl("EXE Created without Struct ocp");
		return (1);

	}
	if (set_args_values(process, arena, &i) == 0)
		return (0);
//	ft_putendl("END --> go back to start");
	inc_pc(process, -process->exe_op->ocp_op->size_adv);
	if (is_failed_reg_nbr(process->exe_op, process->exe_op->arg1) == 0)
	{
		if (process->exe_op->arg2 && is_failed_reg_nbr(process->exe_op, process->exe_op->arg2) == 0)
			is_failed_reg_nbr(process->exe_op, process->exe_op->arg3);
	}
	if (arena->opts->has_b == 1)
		print_exe(process->exe_op);
	return (1);
}

/* REMARQUES & TODOs
 *
 * LE PC avance lors de la creation de l'EXE : Attention si PC == MEM_SIZE
 * DATA --> en char ou char * --> Attention Limit
 * la Value et la data d'un arg en INT non geree (cas ou size > 1) --> done
 */
