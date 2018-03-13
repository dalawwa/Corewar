/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:24:22 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:24:23 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_ld(t_arena *arena, t_exe *exe)
{
	int	i;

	i = 0;
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		ft_printf("%d ", exe->arg1->d_data);
		ft_printf("r%hd\n", (short int)exe->arg2->d_value);
	}
}

int		op_ld(t_arena *arena, t_exe *exe)
{
	print_ld(arena, exe);
	exe->process->reg[exe->arg2->d_value][0] = exe->arg1->data[0];
	exe->process->reg[exe->arg2->d_value][1] = exe->arg1->data[1];
	exe->process->reg[exe->arg2->d_value][2] = exe->arg1->data[2];
	exe->process->reg[exe->arg2->d_value][3] = exe->arg1->data[3];
	print_exe_opts(arena, exe);
	is_carry_to_modify(exe);
	return (1);
}
