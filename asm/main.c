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

#include "../libft/includes/libft.h"

void	check_valid_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 3 || str[i - 1] != 's' || str[i - 2] != '.')
	{
		ft_putstr("Usage: ./asm <sourcefile.s>\n");
		_exit(0);
	}
	return ;
}

int	launch_parsing(char *str)
{
	check_valid_name(str);
	ft_putstr("OK\n");
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

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
