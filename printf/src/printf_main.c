/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:00:06 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/11 15:48:27 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define		_TEST_ "Gautier%-##0 +4.24hhc\n", "123"
//#define		_TEST2_ "Gautier%-##0 4.24hhc\n", 123
//#define		_TEST3_ "Gautier%##0 +4.24hhc\n", 123
//#define		_TEST4_ "Gautier%##0 +.hhc\n", 123

int		main()
{
	
	//printf(_TEST_);
	ft_printf(_TEST_);
	ft_putchar('\n');
	//printf(_TEST2_);
//	ft_printf(_TEST2_);
//	ft_putchar('\n');
	//printf(_TEST3_);
//	ft_printf(_TEST3_);
//	ft_putchar('\n');
	//printf(_TEST4_);
//	ft_printf(_TEST4_);
//	ft_putchar('\n');
	//printf("Cela vaut %+4.1kd francs", 7);
	//printf("Cela vaut %+4.1kd francs", 7);
	//printf("Cela vaut %+4.1kd francs", 7);
	/*printf("Je suis a la %  %    %   %       %   % res maisons mais pas toi t c cool\n");
	printf("Je suis a la %   maison mais pas toi t c cool\n");
	printf("Je suis a la %+d %       maison mais pas toi t c cool\n", 12);
	printf("Je suis a la %%%%maison mais pas toi t c cool\n");*/
	return (0);
}
