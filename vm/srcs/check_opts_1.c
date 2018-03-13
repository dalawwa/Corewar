/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opts_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:21:55 by vbaudron          #+#    #+#             */
/*   Updated: 2018/03/13 10:21:56 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	set_opt_flag(t_opt *opts, int flag, int val)
{
	if (flag == 1)
	{
		opts->has_d = 1;
		opts->d = val;
	}
	if (flag == 2)
	{
		opts->has_s = 1;
		opts->s = val;
	}
	if (flag == 3)
	{
		opts->has_v = 1;
		opts->v = (char)val;
		set_v_values(opts, (char)val);
	}
}

void	set_v_values(t_opt *opts, int val)
{
	if (val > 31)
		val = val % 32;
	opts->is_v0 = 1;
	opts->is_v1 = val & 1;
	opts->is_v2 = val & 2;
	opts->is_v4 = val & 4;
	opts->is_v8 = val & 8;
	opts->is_v16 = val & 16;
}

void	handle_a_b(t_opt *opts, int **flag_indx, int ac, char **av)
{
	if (*flag_indx[0] == 4)
	{
		opts->a_stealth = 0;
		opts->has_a = 1;
		if (*flag_indx[1] + 1 < ac && !ft_strcmp(av[*flag_indx[1] + 1], "--stealth"))
		{
			opts->a_stealth = 1;
			(*flag_indx)[1]++;
		}
	}
	else if (*flag_indx[0] == 5)
	{
		opts->b_stealth = 0;
		opts->has_b = 1;
		if (*flag_indx[1] + 1 < ac && !ft_strcmp(av[*flag_indx[1] + 1], "--stealth"))
		{
			opts->b_stealth = 1;
			(*flag_indx)[1]++;
		}
		*flag_indx[0] = 0;
	}
}

int		check_opts_flags(t_opt *opts, int *flag_indx, int ac, char **av)
{
	if (flag_indx[0] < 4 && flag_indx[0] > 0 && flag_indx[1] + 1 >= ac)
	{
		ft_printf("Can't read source file %s\n", av[flag_indx[1]]);
		return (0);
	}
	if (flag_indx[0] < 6 && flag_indx[0] > 0)
	{
		if (flag_indx[1] + 1 < ac && flag_indx[0] < 4)
		{
			flag_indx[1]++;
			set_opt_flag(opts, flag_indx[0], ft_atoi(av[flag_indx[1]]));
			flag_indx[0] = 0;
		}
		else if (flag_indx[0] == 4 || flag_indx[0] == 5)
			handle_a_b(opts, &flag_indx, ac, av);
		else
		{
			ft_printf("Can't read source file %s\n", av[flag_indx[1]]);
			return (0);
		}
	}
	return (1);
}