/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:46:05 by srossi            #+#    #+#             */
/*   Updated: 2018/08/02 16:06:15 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_clean_label(char *label)
{
	char	*clean_label;
	int		label_ln;

	clean_label = NULL;
	label_ln = ft_strlen(label);
	if (label[0] == LABEL_CHAR)
		clean_label = ft_strsub(label, 1, label_ln - 1);
	else if (label[0] == DIRECT_CHAR && label[1] == LABEL_CHAR)
		clean_label = ft_strsub(label, 2, label_ln - 2);
	else if (label[label_ln - 1] == LABEL_CHAR)
		clean_label = ft_strsub(label, 0, label_ln - 1);
	return (clean_label);
}

t_token		*ft_find_label(t_token *atoken, char *label)
{
	t_token	*p_token;
	char	*clean_label;
	char	*clean_label_token;

	clean_label = ft_clean_label(label);
	clean_label_token = NULL;
	p_token = atoken;
	while (p_token)
	{
		clean_label_token = ft_clean_label(p_token->s_val);
		if (p_token->type == T_LAB &&
				ft_strequ(clean_label_token, clean_label))
			break ;
		p_token = p_token->next;
		ft_strdel(&clean_label_token);
	}
	ft_strdel(&clean_label_token);
	ft_strdel(&clean_label);
	return (p_token);
}

void		ft_fill_labels(t_token *atoken)
{
	t_token *p_token_src;
	t_token *p_token_dst;

	p_token_src = atoken;
	p_token_dst = atoken;
	while (p_token_src)
	{
		p_token_dst = atoken;
		if (p_token_src->type == T_IND_LAB || p_token_src->type == T_DIR_LAB)
		{
			p_token_dst = ft_find_label(p_token_dst, p_token_src->s_val);
			if (p_token_dst == NULL)
			{
				ft_printf("No such label %s while attempting to dereference \
token [TOKEN][%.3d:%.3d] %s \"%s\"\n", ft_clean_label(p_token_src->s_val)
, p_token_src->line, p_token_src->cl + 1, ft_type_char(p_token_src->type)
, p_token_src->s_val);
				exit(EXIT_FAILURE);
			}
			p_token_src->i_val = p_token_dst->pos - p_token_src->last_op_pos;
		}
		p_token_src = p_token_src->next;
	}
}
