/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:38:31 by srossi            #+#    #+#             */
/*   Updated: 2018/08/01 18:39:37 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_open_champ(char *path)
{
	int		fp;
	char	*champ_file;

	champ_file = ft_strjoin(path, ".cor");
	fp = 0;
	fp = open(champ_file, O_WRONLY | O_CREAT | O_TRUNC, 00700);
	ft_strdel(&champ_file);
	return (fp);
}
