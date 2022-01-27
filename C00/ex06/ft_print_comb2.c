/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:07:06 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/13 16:35:29 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	c0;
	int	c1;

	c0 = 0;
	while (c0 <= 98)
	{
		c1 = c0 + 1;
		while (c1 <= 99)
		{
			ft_putchar(c0 / 10 + 48);
			ft_putchar(c0 % 10 + 48);
			ft_putchar(' ');
			ft_putchar(c1 / 10 + 48);
			ft_putchar(c1 % 10 + 48);
			if (c0 < 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			c1++;
		}
		c0++;
	}
}
