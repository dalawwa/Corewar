/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:22:38 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:22:39 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_failed_reg_nbr(t_exe *exe, t_arg *arg)
{
	if (arg && arg->type == 'r' && (arg->d_value > REG_NUMBER || arg->d_value < 1))
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
		{
			exe_op->ocp_op = bdd_op->ocp[i];
			return (1);
		}
		i++;
	}
	exe_op->ocp_op = NULL;
	return (0);
}

int			set_indirect_data(t_arg *arg, t_arena *arena, int pc_tmp)
{
	arg->data = malloc(sizeof(unsigned char) * 4);
	if (arg->data == NULL)
		return (perror_int("Error ", 0));
	pc_tmp = find_pc_adv(pc_tmp, arg->d_value, 0);
	arg->data[0] = arena->mem[pc_tmp];
	pc_tmp = find_pc_adv(pc_tmp, 1, 0);
	arg->data[1] = arena->mem[pc_tmp];
	pc_tmp = find_pc_adv(pc_tmp, 1, 0);
	arg->data[2] = arena->mem[pc_tmp];
	pc_tmp = find_pc_adv(pc_tmp, 1, 0);
	arg->data[3] = arena->mem[pc_tmp];
	arg->d_data = a_hexa_to_i(arg->data, 4);
	return (1);
}

int			set_data(t_arg *arg, t_arena *arena, t_proc *process, int i)
{
	int	pc_tmp;

	pc_tmp = find_pc_adv(process->pc, -i, 0);
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
		set_indirect_data(arg, arena, pc_tmp);
	else
	{
		arg->data = 0;
		arg->d_data = 0;
	}
	return (1);
}

int		fill_new_exe(t_arena *arena, t_proc *process)
{
	int	i;

	i = 1;
	inc_pc(process, 1);
	if (process->exe_op->bdd_op->has_ocp == 1)
	{
		process->exe_op->ocp = arena->mem[process->pc];
		inc_pc(process, 1);
		i++;
	}
	if (find_struct_ocp(process->exe_op, process->exe_op->bdd_op) == 0)
	{
		inc_pc(process, -i);
		return (1);
	}
	if (set_args_values(process, arena, &i) == 0)
		return (0);
	inc_pc(process, -process->exe_op->ocp_op->size_adv);
	if (is_failed_reg_nbr(process->exe_op, process->exe_op->arg1) == 0)
	{
		if (process->exe_op->arg2 && is_failed_reg_nbr(process->exe_op, process->exe_op->arg2) == 0)
			is_failed_reg_nbr(process->exe_op, process->exe_op->arg3);
	}
	return (1);
}
