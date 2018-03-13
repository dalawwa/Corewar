/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:54:05 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:54:06 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_player_i(t_play *player_i, unsigned char *mem)
{
	int	i;

	i = 0;
	while (i < player_i->body_len)
	{
		mem[player_i->idx_start + i] = player_i->body[i];
		i++;
	}
}

int		setup_players(t_arena *arena)
{
	int	i;

	i = 0;
	while (i < arena->nb_players)
	{
		set_player_i(arena->players[i], arena->mem);
		i++;
	}
	return (1);
}
