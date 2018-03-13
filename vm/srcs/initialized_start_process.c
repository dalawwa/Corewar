/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialized_start_process.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:23:36 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:23:36 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		initialized_start_process(t_arena *arena)
{
	int		i;

	i = 0;
	while (i < arena->nb_players)
	{
		if ((create_new_process(arena, arena->players[i], NULL)) == 0)
			return (0);
		i++;
	}
	return (1);
}
