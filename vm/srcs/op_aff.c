/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:24:11 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:24:12 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		op_aff(t_arena *arena, t_exe *exe)
{
	int	i;

	i = a_hexa_to_i(exe->process->reg[exe->arg1->d_value], 4) % 256;
	if (arena->opts->has_a == 1)
		ft_printf("Aff: %c\n", i);
	print_exe_opts(arena, exe);
	return (1);
}
