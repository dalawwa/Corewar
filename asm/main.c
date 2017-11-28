/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:29:39 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/27 17:49:04 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		if (av[i][0] == '-' && av[i][1] == 'a' && ac > 2)
			i++;
		launch_parsing(av[i]);
	}
	else
		ft_putstr("Usage: ./asm <sourcefile.s>\n");
	return (0);
}