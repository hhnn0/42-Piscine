/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:21:35 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/22 13:04:59 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_arr[10];
int	g_count = 0;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	is_possible(int depth)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		if (g_arr[depth] == g_arr[i])
			return (0);
		else if (abs(g_arr[depth] - g_arr[i]) == abs(depth - i))
			return (0);
		i++;
	}
	return (1);
}

void	dfs(int depth)
{
	int	i;

	i = 0;
	if (depth == 10)
	{
		while (i < 10)
		{
			ft_putchar(g_arr[i] + 48);
			i++;
		}
		ft_putchar('\n');
		g_count++;
		return ;
	}
	while (i < 10)
	{
		g_arr[depth] = i;
		if (is_possible(depth))
			dfs(depth + 1);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	dfs(0);
	return (g_count);
}
