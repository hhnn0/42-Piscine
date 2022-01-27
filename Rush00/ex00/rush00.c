/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:26:38 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/09 17:22:35 by hyunhkim         ###   ########.fr       */
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
		if (cnt == 0 || cnt == y - 1)
		{
			put_line(x, 'o', '-');
		}
		else
		{
			put_line(x, '|', ' ');
		}
		cnt++;
	}
}
