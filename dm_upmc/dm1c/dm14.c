/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm14.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:41:13 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/08 18:55:51 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 0
#define MAX 100

int main()
{
	int k = 0, nombre, somme = 0;

	srand(time(NULL));
	do {
		nombre = MIN + rand() % (MAX - MIN);
		k++;
		somme = somme + nombre;
	} while (nombre >= 10);
	printf("nombre de tirages : %d somme : %d", k, somme);
	return (0);
}
