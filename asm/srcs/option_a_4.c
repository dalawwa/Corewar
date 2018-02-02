/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_a_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:14:13 by bfruchar          #+#    #+#             */
/*   Updated: 2018/01/30 15:15:11 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	treat_and_or_xor(char *str, int i)
{
	g_temp += 2;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == 'r')
		g_temp++;
	else if (str[i] == '%')
		g_temp += 4;
	else
		g_temp += 2;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == 'r')
		g_temp++;
	else if (str[i] == '%')
		g_temp += 4;
	else
		g_temp += 2;
}

void	treat_ldi_lldi(char *str, int i)
{
	g_temp += 2;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == 'r')
		g_temp++;
	else
		g_temp += 2;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == 'r')
		g_temp++;
	else
		g_temp += 2;
}

void	treat_ld_lld(char *str, int i)
{
	g_temp += 2;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '%')
		g_temp += 4;
	else
		g_temp += 2;
}

void	treat_sti(char *str, int i)
{
	g_temp += 2;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == 'r')
		g_temp += 1;
	else
		g_temp += 2;
	while (str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == 'r')
		g_temp += 1;
	else
		g_temp += 2;
}

void	temp_advance(int co, char *str)
{
	if (co == 1 || co == 4 || co == 5)
		g_temp += 4;
	else if (co == 2 || co == 13)
		treat_ld_lld(str, 0);
	else if (co == 3)
		treat_and_temp(str, 0);
	else if (co == 6 || co == 7 || co == 8)
		treat_and_or_xor(str, 0);
	else if (co == 9 || co == 12 || co == 15)
		g_temp += 2;
	else if (co == 10 || co == 14)
		treat_ldi_lldi(str, 0);
	else if (co == 11)
		treat_sti(str, 0);
	else if (co == 16)
		g_temp++;
	if (co)
		g_temp++;
}
