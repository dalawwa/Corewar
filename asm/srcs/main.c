/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:29:39 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/09 16:35:39 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
//		we need to check if there is the option -a
//		this option can be everywhere in the option

int	main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		global_variables_size();
		launch_parsing(av[1]);
	}
	else
		ft_putstr("Usage: ./asm <sourcefile.s>\n");
	return (0);
}
