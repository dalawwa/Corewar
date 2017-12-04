/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfruchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:30:09 by bfruchar          #+#    #+#             */
/*   Updated: 2017/12/04 10:36:30 by bfruchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		ft_splitwords(char **result, const char *s, char c, char d, char e)
{
	int			i;
	size_t		len;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && (*s == c || *s == d || *s == e))
			++s;
		if (*s)
		{
			while (s[len] && (s[len] != c && s[len] != d && s[len] != e))
				++len;
			if (!(result[i] = ft_strnew(len)))
				return (0);
			ft_strncpy(result[i], s, len);
			s += len;
			++i;
		}
	}
	result[i] = NULL;
	return (1);
}

static size_t	ft_countwords(const char *s, char c, char d, char e)
{
	size_t nbwords;
	size_t i;

	nbwords = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == d || s[i] == e))
			++i;
		while (s[i] && (s[i] != c && s[i] != d && s[i] != d))
			++i;
		++nbwords;
	}
	return (nbwords);
}

char			**ft_strsplit_three(const char *s, char c, char d, char e)
{
	char		**result;
	size_t		nbwords;

	if (!s || !c || !d || !e)
		return (NULL);
	if (!s[0])
	{
		if (!(result = ft_memalloc(sizeof(char*) * 1)))
			return (NULL);
		result[0] = NULL;
		return (result);
	}
	nbwords = ft_countwords(s, c, d, e);
	if (!(result = ft_memalloc(sizeof(char*) * (nbwords + 1))))
		return (NULL);
	if (!ft_splitwords(result, s, c, d, e))
		return (NULL);
	return (result);
}
