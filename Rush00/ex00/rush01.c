/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.422seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:38:17 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/09 17:25:42 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	put_line(int num, char side, char mid)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (i == 0 || i == num - 1)
		{
			ft_putchar(side);
		}
		else
		{
			ft_putchar(mid);
		}
		i++;
	}
	ft_putchar('\n');
}

void	put_line2(int num, char first, char mid, char last)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (i == 0)
		{
			ft_putchar(first);
		}
		else if (i == num - 1)
		{
			ft_putchar(last);
		}
		else
		{
			ft_putchar(mid);
		}
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	cnt;

	cnt = 0;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	while (cnt < y)
	{
		if (cnt == 0)
		{
			put_line2(x, '/', '*', '\\');
		}
		else if (cnt == y - 1)
		{
			put_line2(x, '\\', '*', '/');
		}
		else
		{
			put_line(x, '*', ' ');
		}
		cnt++;
	}
}
