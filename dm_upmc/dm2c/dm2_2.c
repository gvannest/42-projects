/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm2_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:44:33 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/02 10:13:02 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
/*
 fonction doit retourner deux entiers. Nous choisissons de déclarer une
 fonction ayant deux paramètres passés par adresse. Chacun d’eux devant
 permettre de récupérer un des deux résultats calculés par la fonction.
 La fonction ne  retourne donc aucune valeur.
*/

void	moments(int *tab, int n, float *moyenne, float *variance)
{
	float somme = 0;
	float somme_ecart = 0;
	int i;

	*moyenne = 0;
	*variance = 0;
	for (i = 0; i < n; i++)
		somme = somme + tab[i];
	*moyenne = somme / n;
	for (i = 0; i < n; i++)
		somme_ecart = somme_ecart + (tab[i] - *moyenne)*(tab[i] - *moyenne);
	*variance = somme_ecart / n;
}

int main()
{
	int tab[5] = {2, 6, 7, 1, 12};
	float m;
	float v;

	moments(tab, 5, &m, &v);
	printf("%f\n%f\n", m, v);
}



