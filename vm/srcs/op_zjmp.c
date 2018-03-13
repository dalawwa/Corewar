/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:53:29 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:53:30 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		op_zjmp(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		ft_printf("%hd", (short)exe->arg1->d_value);
		if (exe->process->carry == 1)
			ft_printf(" OK\n");
		else
		{
			ft_printf(" FAILED\n");
			print_exe_opts(arena, exe);
		}
	}
	if (exe->process->carry == 1)
	{
		inc_pc(exe->process, (short)exe->arg1->d_value % IDX_MOD);
		return (1);
	}
	inc_pc(exe->process, 3);
	return (0);
}
