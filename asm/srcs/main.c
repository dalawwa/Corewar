/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:29:39 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/29 11:13:42 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
//		we need to check if there is the option -a
//		this option can be everywhere in the option
//		we just need to know that the last av should be the file
/*		while (i < ac)
		{
			if (av[i][0] == '-' && av[i][1] == 'a' && ac > 2)
				;
			i++;
		}*/
		global_variables_size();
		launch_parsing(av[1]);
	}
	else
		ft_putstr("Usage: ./asm <sourcefile.s>\n");
	return (0);
}
