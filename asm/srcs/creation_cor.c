/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_cor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:39:50 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/18 17:50:06 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"


//obtenir le nom du fichier et creer un char *.cor qui servira a enregistrer le new file
//create and launch with OPEN (READ &WRITE) with the file.cor
//create file with magic numbers, name of the program, then command
//then use the file to print everything to have a good asm
int		launch_creation_cor(char *file, t_champ *champ, header_t *op, char *str)
{
	str = NULL;
	file = NULL;
	champ  = NULL;
	op = NULL;
	return (1);
}
