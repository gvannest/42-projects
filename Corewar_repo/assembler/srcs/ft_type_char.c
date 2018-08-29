/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:20:34 by srossi            #+#    #+#             */
/*   Updated: 2018/08/01 16:20:49 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_type_char(int type)
{
	if (type == T_DIR)
		return ("DIRECT");
	else if (type == T_DIR_LAB)
		return ("DIRECT LABEL");
	else if (type == T_IND_LAB)
		return ("INDIRECT LABEL");
	else if (type == T_IND)
		return ("INDIRECT");
	else if (type == T_REG)
		return ("REGISTER");
	else if (type == T_LAB)
		return ("LABEL");
	else
		return ("UNKNOWN TYPE");
}
