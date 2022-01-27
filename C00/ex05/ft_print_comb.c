/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:06:12 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/13 16:35:19 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_comma(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	put_char(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
}

void	ft_print_comb(void)
{
	char	c0;
	char	c1;
	char	c2;

	c0 = '0';
	while (c0 <= '7')
	{
		c1 = c0 + 1;
		while (c1 <= '8')
		{
			c2 = c1 + 1;
			while (c2 <= '9')
			{
				put_char(c0, c1, c2);
				if (c0 < '7')
				{
					put_comma();
				}
				c2++;
			}
			c1++;
		}
		c0++;
	}
}
