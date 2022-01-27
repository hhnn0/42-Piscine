/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:51:51 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/16 20:52:36 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "rush.h"

t_MaxSeeBox	g_see_box;

static int	g_map[4][4];
static int	g_check_col[5][5];
static int	g_check_row[5][5];
static int	g_count = 0;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_map(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(g_map[i][j] + 48);
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	g_count++;
}

void	g_check(int x, int y, int value, int flag)
{
	g_check_row[x][value] = flag;
	g_check_col[y][value] = flag;
	g_map[x][y] = value;
}

void	solve(int num)
{
	int	x;
	int	y;
	int	i;

	if (num == 16)
	{
		if (is_view_ok(g_map, g_see_box))
			print_map();
		return ;
	}
	x = num / 4;
	y = num % 4;
	i = 1;
	while (i <= 4)
	{
		if ((!g_check_row[x][i] && !g_check_col[y][i]))
		{
			g_check(x, y, i, 1);
			solve(num + 1);
			g_check(x, y, i, 0);
		}
		i++;
	}
}

int	rush(t_MaxSeeBox see_box)
{
	g_see_box = see_box;
	solve(0);
	if (g_count == 0)
		return (0);
	return (1);
}
