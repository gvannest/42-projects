/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:18:24 by achirat           #+#    #+#             */
/*   Updated: 2017/11/15 17:32:10 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *s, char c)
{
	int		words;

	words = 0;
	while (*s != '\0')
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (words);
		while (*s != c && *s)
			s++;
		words++;
	}
	return (words);
}

static int		*ft_letters(char const *s, char c)
{
	int		letters;
	int		*tab;
	int		ind;

	ind = 0;
	ind = 0;
	if (!(tab = (int*)malloc(sizeof(*tab) * ft_words(s, c))))
		return (0);
	while (*s != '\0')
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (tab);
		letters = 0;
		while (*s != c && *s)
		{
			s++;
			letters++;
		}
		tab[ind] = letters;
		ind++;
	}
	return (tab);
}

static char		**ft_remplissage(char **str, char const *s, char c)
{
	int		b;
	int		a;

	a = 0;
	while (*s != '\0')
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
		{
			str[a] = 0;
			return (str);
		}
		b = 0;
		while (*s != c && *s)
		{
			str[a][b] = *s;
			s++;
			b++;
		}
		str[a][b] = '\0';
		a++;
	}
	str[a] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		ind;
	int		*tab;
	char	**str;

	ind = 0;
	if (!s || !c)
		return (0);
	tab = ft_letters(s, c);
	if (!(str = (char**)malloc(sizeof(*str) * (ft_words(s, c) + 1))))
		return (0);
	while (ind < ft_words(s, c))
	{
		str[ind] = (char*)malloc(sizeof(**str) * (tab[ind] + 1));
		if (str[ind] == NULL)
		{
			ind = ind - 1;
			while ((ind--) >= 0)
				free(str[ind]);
			free(str);
			return (0);
		}
		ind++;
	}
	return (ft_remplissage(str, s, c));
}
