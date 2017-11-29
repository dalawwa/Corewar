/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:45:13 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/29 11:13:52 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

//lignes vide ou commentaire non merci
int		this_is_a_comment(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '#')
		return (1);
	else
		return (0);
}

//on va recuperer la liste du fichier que l on va mettre dans une liste doublement chainee
//on ne va pas recuperer les lignes vides et les commentaires
void	get_champ_data(t_champ *champ, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		if (check_no_printable_char(line) || this_is_a_comment(line))
			;
		else 
			ft_lstadd_lines(&champ, line, i);
	}
	return ;
}
