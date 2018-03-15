/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:53:49 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/15 14:35:32 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	print_usage(void)
{
	ft_putstr("Usage: ./corewar [-d N -s N -v N | -b --stealth |");
	ft_putstr(" -n --stealth] [-a] <champion1.cor> <...>\n");
	ft_putstr("\t-a\t\t: Prints output from aff (Default is to hide it)\n");
	ft_putstr("#### TEXT OUTPUT MODE ");
	ft_putstr("##########################################################\n");
	ft_putstr("\t-d N\t\t: Dumps memory after N cycles then exits\n");
	ft_putstr("\t-b\t\t: Show process after OP\n");
	ft_putstr("\t-s N\t\t: Runs N cycles, dumps memory, then ");
	ft_putstr("repeats\n\t-v N\t\t: Verbosity levels, can be added together");
	ft_putstr(" to enable several\n\t\t\t\t- 0 : Show only essentials\n");
	ft_putstr("\t\t\t\t- 1 : Show lives\n");
	ft_putstr("\t\t\t\t- 2 : Show cycles\n");
	ft_putstr("\t\t\t\t- 4 : Show operations (Params are NOT litteral ...)\n");
	ft_putstr("\t\t\t\t- 8 : Show deaths\n");
	ft_putstr("\t\t\t\t- 16 : Show PC movements (Except for jumps)\n");
	ft_putstr("#### NCURSES OUTPUT MODE ");
	ft_putstr("##########################################################\n");
	ft_putstr("\t-n\t\t: Ncurses output mode\n");
	return (0);
}
