/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm2_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:21:22 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/02 09:43:43 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	statistique(char *str, int *tab)
{
	int i = 0;
	char c;
	char C;

	while (str[i] != '\0')
	{
		c = 'a';
		C = 'A';
		while (c <= 'z' && C <= 'Z')
		{
			if (str[i] == c)
				tab[c - 'a']++;
			if (str[i] == C)
				tab[C - 'A']++;
			c++;
			C++;
		}
		i++;
	}
	i = 0;
	while (i < 26)
		printf("%d", tab[i++]);
}

int main()
{
	int	tab[26];
	int i = 0;
	char	*str;

	str = "abAAcdeDdCce";
	
	while (i < 26)
		tab[i++] = 0;
	statistique(str, tab);
	return (0);
}

