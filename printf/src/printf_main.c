/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:00:06 by gvannest          #+#    #+#             */
/*   Updated: 2017/12/22 15:24:05 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	char str[100] = "%%Le chat est sur le%%%% c'est cool\n";
	
	//printf(
	ft_putnbr(ft_printf(str));
	ft_putchar('\n');
	ft_putnbr(printf("%%Le chat est sur le%%%% c'est cool\n"));
	ft_putchar('\n');
	/*printf("Je suis a la %  %    %   %       %   % res maisons mais pas toi t c cool\n");
	printf("Je suis a la %   maison mais pas toi t c cool\n");
	printf("Je suis a la %+d %       maison mais pas toi t c cool\n", 12);
	printf("Je suis a la %%%%maison mais pas toi t c cool\n");*/
	return (0);
}
