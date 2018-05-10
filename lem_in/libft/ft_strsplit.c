/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:11:14 by gvannest          #+#    #+#             */
/*   Updated: 2018/04/30 16:31:26 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_ctwords(char const *s, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!(s[i]))
			return (k);
		while (s[i] != c && s[i])
			i++;
		k++;
	}
	return (k);
}

static	size_t	*ft_ctletters(const char *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	j;
	size_t	*tab;

	i = 0;
	j = 0;
	if (!(tab = (size_t*)malloc(sizeof(*tab) * ft_ctwords(s, c))))
		return (0);
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!(s[i]))
			return (tab);
		while (s[i] != c && s[i])
		{
			i++;
			k++;
		}
		tab[j] = k;
		j++;
	}
	return (tab);
}

static	char	**ft_fill(char **pointeur, char const *s, char c)
{
	size_t	n;
	size_t	m;

	n = 0;
	while (*s)
	{
		m = 0;
		while (*s && *s == c)
			s++;
		if (!(*s))
		{
			pointeur[n] = 0;
			return (pointeur);
		}
		while (*s != c && *s)
		{
			pointeur[n][m] = *s;
			s++;
			m++;
		}
		pointeur[n][m] = '\0';
		n++;
	}
	pointeur[n] = 0;
	return (pointeur);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**ptr;
	size_t	*tab;

	if (!s)
		return (0);
	i = 0;
	if (!(ptr = (char**)malloc(sizeof(*ptr) * (ft_ctwords(s, c) + 1))))
		return (0);
	tab = ft_ctletters(s, c);
	while (i < ft_ctwords(s, c))
	{
		if (!(ptr[i] = (char*)malloc(sizeof(**ptr) * (tab[i] + 1))))
		{
			while (i-- > 0)
				free(ptr[i]);
			free(ptr);
			return (0);
		}
		i++;
	}
	free(tab);
	return (ft_fill(ptr, s, c));
}
