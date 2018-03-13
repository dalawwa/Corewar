/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_char_at_mem_pc_adv.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:22:50 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:22:52 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	find_char_at_mem_pc_adv(int pc, int adv, t_arena *arena)
{
	int	i;

	i = 0;
	return (arena->mem[get_adv(pc + adv)]);
}
