/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:45:13 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/27 17:59:54 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//on va recuperer la liste du fichier que l on va mettre dans une liste doublement chainee
//a continuer ici
void	get_champ_data(t_champ *champ, int fd)
{
	char	*line;

	line = NULL;
	champ->position = 1;
	while (get_next_line(fd, &line) > 0)
	{
		while (check_no_printable_char(line))
			get_next_line(fd, &line);
	}
	return ;
}
