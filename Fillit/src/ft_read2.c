/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 09:55:35 by achirat           #+#    #+#             */
/*   Updated: 2017/11/30 10:49:55 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check2(char *str)
{
	int	a;

	a = 0;
	while (*str)
	{
		if (*str == '#' && *(str + 1) == '#')
			a++;
		if (*str == '#' && *(str - 1) == '#')
			a++;
		if (*str == '#' && *(str + 5) == '#')
			a++;
		if (*str == '#' && *(str - 5) == '#')
			a++;
		str++;
	}
	return (a);
}

static int		ft_check(char *str)
{
	size_t	a;
	size_t	pt;
	size_t	diese;
	size_t	line;

	pt = 0;
	diese = 0;
	a = 0;
	line = 0;
	while (str[a] && (str[a] != '.' || str[a] != '#'))
	{
		if (str[a] == '.')
			pt++;
		if (str[a] == '#')
			diese++;
		a++;
	}
	if (pt == 12 && diese == 4)
		return (1);
	else
		return (0);
}

static t_list	*ft_verif(int fd, t_list *alst, size_t *octet)
{
	int		ret;
	char	str[BUFF_SIZE + 1];
	char	let;

	let = 'A';
	while ((ret = read(fd, str, BUFF_SIZE)))
	{
		str[BUFF_SIZE] = '\0';
		if (str[0] == '\n' || ft_check(str) != 1 || ft_check2(str) < 6)
		{
			ft_putendl("error");
			exit(0);
		}
		ft_stock(str, &alst, let);
		*octet = *octet + ret;
		let++;
	}
	if (*octet == 0)
	{
		ft_putendl("error");
		exit(0);
	}
	return (alst);
}

t_list			*ft_read(char *av, size_t *octet)
{
	int		fd;
	t_list	*alst;

	alst = NULL;
	if ((fd = open(av, O_RDWR)) == -1)
		exit(EXIT_FAILURE);
	alst = ft_verif(fd, alst, octet);
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	ft_lstrev(&alst);
	return (alst);
}
