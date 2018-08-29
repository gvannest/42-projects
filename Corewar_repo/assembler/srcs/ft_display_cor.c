/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_cor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:48:34 by srossi            #+#    #+#             */
/*   Updated: 2018/08/02 16:05:00 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	ft_display_champ(t_asm *info)
{
	int		index;
	t_token *p_token;
	int		champ_ln;

	index = 0;
	p_token = info->atoken;
	while (p_token->next)
		p_token = p_token->next;
	champ_ln = p_token->pos + p_token->arg_size;
	while (index < champ_ln)
	{
		if (index % 16 == 0)
			ft_printf("\n");
		else if (index % 2 == 0 && index != 0)
			ft_printf(" ");
		ft_printf("%.2hhx", info->tab[index]);
		index++;
	}
}

static	void	ft_display_name(char *name)
{
	int index;

	index = 0;
	while (index < PROG_NAME_LENGTH)
	{
		if ((index + 4) % 16 == 0)
			ft_printf("\n");
		else if (index % 2 == 0 && index != 0)
			ft_printf(" ");
		ft_printf("%.2x", name[index]);
		index++;
	}
	ft_printf(" ");
}

static	void	ft_display_comment(char *comment)
{
	int index;

	index = 0;
	while (index < COMMENT_LENGTH)
	{
		if ((index + 12) % 16 == 0 && index != 0)
			ft_printf("\n");
		else if (index % 2 == 0 && index != 0)
			ft_printf(" ");
		ft_printf("%.2x", comment[index]);
		index++;
	}
	ft_printf(" ");
}

static	void	ft_display_int(int nb)
{
	unsigned char	octets[4];
	int				index;

	index = 0;
	octets[0] = nb >> 0;
	octets[1] = nb >> 8;
	octets[2] = nb >> 16;
	octets[3] = nb >> 24;
	ft_swap_bytes_int(octets);
	ft_printf("%.2x%.2x %.2x%.2x ", octets[0], octets[1], octets[2], octets[3]);
}

void			ft_display(t_asm *info)
{
	int magic;

	magic = 0x00EA83F3;
	ft_display_int(magic);
	ft_display_name(info->name);
	ft_display_int(0);
	ft_display_int(info->pos);
	ft_display_comment(info->comment);
	ft_display_int(0);
	ft_create_champ(info);
	ft_display_champ(info);
}
