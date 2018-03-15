/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:24:08 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 12:34:23 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_add_sub(t_arena *arena, t_exe *exe)
{
	if (arena->opts->is_v4)
	{
		print_proc_num_name(exe);
		ft_printf("r%hd r%hd r%hd\n", (short)exe->arg1->d_value,
		(short)exe->arg2->d_value, (short)exe->arg3->d_value);
	}
}

int		op_add(t_arena *arena, t_exe *exe)
{
	unsigned int	result;
	unsigned char	*s;

	print_add_sub(arena, exe);
	result = exe->arg1->d_data + exe->arg2->d_data;
	s = ft_ito_hexa(result);
	if (s == NULL)
		return (-1);
	exe->process->reg[exe->arg3->d_value][0] = s[0];
	exe->process->reg[exe->arg3->d_value][1] = s[1];
	exe->process->reg[exe->arg3->d_value][2] = s[2];
	exe->process->reg[exe->arg3->d_value][3] = s[3];
	free(s);
	s = NULL;
	exe->process->carry = result ? 0 : 1;
	print_exe_opts(arena, exe);
	return (1);
}
