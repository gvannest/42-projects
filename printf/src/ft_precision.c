/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:33:30 by gvannest          #+#    #+#             */
/*   Updated: 2018/01/15 17:08:20 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_precision_num(t_lst *p, char *str)
{
	size_t	i;

	i = 0;
	(PRECISION < LEN_PARAM ? PRECISION = LEN_PARAM : PRECISION);
		//	if (PRECISION > LEN_PARAM)
		//	{
		if (!(str = ft_strnew(PRECISION)))
			exit (EXIT_FAILURE);
	ft_memset((void*)str, '0', PRECISION);
	//		if (
	//		str = ft_strncpy(str + PRECISION - LEN_PARAM, ft_itoabase_s((PARAM, BASE));
	//	}
	//	else
	//		str = ft_itoabase_s(PARAM, BASE);
	if (TYPE == 'd' || TYPE == 'D' || TYPE == 'i')
		str = ft_strncpy(str + PRECISION - LEN_PARAM, ft_itoabase_s(*(intmax_t*)PARAM, BASE), LEN_PARAM);
	else
		str = ft_strncpy(str + PRECISION - LEN_PARAM, ft_itoabase_u(*(uintmax_t*)PARAM, BASE), LEN_PARAM);
	return (str);
}

static char	*ft_precision_s(t_lst *p, char *str)
{
	size_t	i;

	i = 0;
	if (PRECISION < LEN_PARAM)
		str = ft_strsub((char*)PARAM, 0, PRECISION);
	else
		str = ft_strdup((char*)PARAM);
	return (str);
}

int		ft_precision(t_lst *p)
{
	char	*result_precision;

	result_precision = 0;
	if (TYPE == 'p' || TYPE == 'c' || TYPE == 'C')
		return (-1);
	else if (TYPE == 's' || TYPE == 'S' )
		RESULT = ft_precision_s(p, result_precision);
	else
		RESULT = ft_precision_num(p, result_precision);
	ft_putchar('\n');
	ft_putendl(RESULT);
	return (1);
}
