/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:18:43 by gvannest          #+#    #+#             */
/*   Updated: 2017/11/09 09:42:54 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	**ft_sort_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		m;
	char	*str;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		m = i;
		while (j < argc)
		{
			if (ft_strcmp(argv[m], argv[j]) > 0)
				m = j;
			j++;
		}
		str = argv[i];
		argv[i] = argv[m];
		argv[m] = str;
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (argv);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_sort_params(argc, argv);
	}
	return (0);
}
