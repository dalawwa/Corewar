/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_exe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:22:20 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:22:21 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		create_new_exe(t_arena *arena, t_proc *process)
{
	process->exe_op = (t_exe *)malloc(sizeof(t_exe));
	if (process->exe_op == NULL)
		return (perror_int("Error ", 0));
	init_exe(process->exe_op, process);
	process->exe_op->opcode = arena->mem[process->pc];
	find_bdd_op(process->exe_op, arena->bdd);
	process->exe_op->to_wait = process->exe_op->bdd_op->nb_cycle;
    return (1);
}
