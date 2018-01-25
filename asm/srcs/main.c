/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:29:39 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/23 11:29:19 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
//		we need to check if there is the option -a
//		this option can be everywhere in the option

int		where_is_a(char **tab)
{
	int		i;

	i = 1;
	while (tab[i] != NULL)
	{
		if (tab[i][0] == '-' && tab[i][1] == 'a'
				&& (tab[i][2] == ' ' || tab[i][2] == '\0'))
			return (i + 1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;

	if (ac > 1)
	{
		i = where_is_a(av);
		if (i != 0)
		{
			if (ac == 2)
			{
				ft_printf("Can't read source file (null)\n");
				return (0);
			}
			if (i == ac)
				i = i - 2;
			launch_parsing(av[i], 0);
			return (0);
		}
		global_variables_size();
		launch_parsing(av[ac - 1], 1);
	}
	else
		ft_putstr("Usage: ./asm <sourcefile.s>\n");
	return (0);
}
