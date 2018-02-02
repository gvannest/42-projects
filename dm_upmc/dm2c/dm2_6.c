/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dm2_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:59:39 by gvannest          #+#    #+#             */
/*   Updated: 2018/02/02 14:24:58 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		escape(int laby[7][7], int caillou[7][7], int N, int i, int j)
{
	if (caillou[i][j] == 1 || laby[i][j] == 1)
		return (0);
	if (i == N - 2 && j == N - 2)
	{
		caillou[i][j] = 1;
		return (1);
	}
	caillou[i][j] = 1;
	if (escape(laby, caillou, N, i + 1, j) == 0)
		if (escape(laby, caillou, N, i, j + 1) == 0)
			if (escape(laby, caillou, N, i - 1, j) == 0)
				if (escape(laby, caillou, N, i, j - 1) == 0)
				{
					caillou[i][j] = 0;
					return (0);
				}
	return (1);
}

int main()
{
	int i = 0;
	int j;

	int		laby[7][7] = {	{1,1,1,1,1,1,1},
							{1,0,1,0,0,0,1},
							{1,0,1,0,1,1,1},
							{1,0,0,0,1,0,1},
							{1,0,1,0,1,0,1},
							{1,0,0,1,1,0,0},
							{1,1,1,1,1,0,0}	};

	int		caillou[7][7] = {	{0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0}	};

	escape(laby, caillou, 7, 1, 1);

	while (i < 7)
	{
		j = 0;
		while (j < 7)
			printf("%d ", caillou[i][j++]);
		printf("\n");
		i++;
	}
	return (0);
}

