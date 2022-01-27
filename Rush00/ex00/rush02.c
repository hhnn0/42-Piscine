/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.422seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:35:55 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/09 17:25:10 by hyunhkim         ###   ########.fr       */
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
			put_line(x, 'A', 'B');
		}
		else if (cnt == y - 1)
		{
			put_line(x, 'C', 'B');
		}
		else
		{
			put_line(x, 'B', ' ');
		}
		cnt++;
	}
}
