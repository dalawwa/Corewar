/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:29:39 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/24 11:29:41 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("Usage: ./asm [-a] <sourcefile.s>\n");
		return (0);
	}
	else
	{
//		launch_compilation(argv[1]);
		return (1);
	}
	return (0);
}
