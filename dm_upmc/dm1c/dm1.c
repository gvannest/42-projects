/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:50:43 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/08 18:14:40 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main()
{
	int n, i = 2, u0 = 1, u1 = 2, v0 = 2, v1 = 1, u_n = 0, v_n = 0;

	printf("Veuillez entrer un entier positif ou nul :\n");
	scanf("%d", &n);
	if (n == 0)
		printf("u_n = %d et v_n = %d", u0, v0);
	else if (n == 1)
		printf("u_n = %d et v_n = %d", u1, v1);
	else
	{
		while (i <= n)
		{
			u_n = u0 + v1;
			v_n = v0 + u1;
			u0 = u1;
			v0 = v1;
			u1 = u_n;
			v1 = v_n;
			i++;
		}
		printf("u_n = %d et v_n = %d", u_n, v_n);
	}
	return (0);
}
