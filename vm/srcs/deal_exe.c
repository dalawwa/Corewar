/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:26:33 by bfruchar          #+#    #+#             */
/*   Updated: 2018/03/15 14:49:05 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_regs(t_proc *process)
{
	int	i;

	i = 1;
	while (i <= REG_NUMBER)
	{
		ft_printf("reg[%d] = %.2x%.2x %.2x%.2x", i, process->reg[i][0],
				process->reg[i][1], process->reg[i][2], process->reg[i][3]);
		i++;
		if (i <= REG_NUMBER)
			ft_putstr(" - ");
	}
	ft_putchar('\n');
}

void		print_process(t_proc *process)
{
	ft_putendl("__Current PROCESS");
	ft_printf("Process num %d :\nCarry = %d - pc = %d\n",
			process->process_num,
			process->carry, process->pc);
	print_regs(process);
	ft_putendl("__END");
}

void		execute_exe(t_arena *arena, t_proc *elem)
{
	int		failed_adv;

	failed_adv = 0;
	fill_new_exe(arena, elem);
	if (elem->is_process_launched == 0)
		elem->is_process_launched = 1;
	if (elem->exe_op->ocp_op != NULL)
	{
		if (elem->exe_op->ocp_op->fct != NULL)
		{
			elem->exe_op->ocp_op->fct(arena, elem->exe_op);
			if (arena->opts->has_b)
				print_process(elem);
		}
		if (elem->exe_op->opcode != 9)
			inc_pc(elem, elem->exe_op->ocp_op->size_adv);
	}
	else
	{
		failed_adv = count_failed_adv(arena, elem->exe_op);
		print_failed_exe(arena, elem->exe_op, failed_adv);
		inc_pc(elem, failed_adv);
	}
	free_exe(elem->exe_op, elem);
}

void		create_or_adv(t_arena *arena, t_proc *elem)
{
	if (is_valid_op(arena, elem) == 1)
	{
		create_new_exe(arena, elem);
		elem->exe_op->to_wait--;
	}
	else
		inc_pc(elem, 1);
}

int			deal_exe(t_arena *arena)
{
	int		i;
	t_proc	*elem;

	i = 0;
	elem = arena->list_proc->last;
	while (i < arena->list_proc->nb_proc)
	{
		if (!elem || elem->exe_op == NULL)
			create_or_adv(arena, elem);
		if (elem->exe_op)
		{
			if (elem->exe_op->to_wait == 0)
				execute_exe(arena, elem);
			else
				elem->exe_op->to_wait--;
		}
		i++;
		elem = elem->prev;
		if (i < arena->list_proc->nb_proc && elem == NULL)
			return (1);
	}
	return (1);
}
