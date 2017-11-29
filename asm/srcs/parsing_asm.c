/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_asm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:37:17 by bfruchar          #+#    #+#             */
/*   Updated: 2017/11/29 11:14:03 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

//On verifie que le fichier est compatible, ".s"
void	check_valid_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 3 || str[i - 1] != 's' || str[i - 2] != '.')
		ciao_bye_bye(1);
	return ;
}

//recuperer le char* entre parentheses, c est a dire le nom et le comment et le mettre dans la structure head
void	value_parent(char *str, int x, int j, t_header *op)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
			{
				i++;
				j++;
			}
			if (x == 1)
			{
				i--;
				while (j--)
				{
					op->prog_name[j] = str[i];
					i--;
				}
			}
			if (x == 2)
			{
				i--;
				while (j--)
				{
					op->comment[j] = str[i];
					i--;
				}
			}
			return ;
		}
		i++;
	}
}

//on va chech qu il s agit bien d une ligne sans autre caractere que des espaces et tabs
int		check_no_printable_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//check que l on retrouve bien .name et .comment au debut du fichier, il peut y avoir des lignes vides avant/apres/entre name et comment et il n y a pas un ordre precis
//verifier de ne pas avoir de ligne a la suite et qui va demarrer par "."
//accepter les commentaires lors de la recherche de ces infos 
void	check_name_comment(int fd, t_header *op)
{
	char	*line;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strnequ(".name", line, 5))
		{
			value_parent(line, 1, 0, op);
			x = 1;
		}
		else if (ft_strnequ(".comment", line, 8))
		{
			value_parent(line, 2, 0, op);
			y = 1;
		}
		else if (check_no_printable_char(line) == 0)
			ciao_bye_bye(1);
		if (x == 1 && y == 1)
			return ;
		i++;
	}
}

//lancement du parsing, on va d abord chercher a recuperer le nom + comment
////dans un second temps on va recuperer toutes les instructions
//une fois que l on a recupere les datas du champion, il va falloir faire leur analyse
int	launch_parsing(char *str)
{
	int			fd;
	t_champ		champ;
	t_header	op;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	check_valid_name(str);
	start_struct_champ(&champ);
	check_name_comment(fd, &op);
	get_champ_data(&champ, fd);
	return (0);
}
