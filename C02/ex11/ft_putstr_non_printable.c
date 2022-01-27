/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_with_non_printable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:52:47 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/18 20:31:08 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_valid(char c)
{
	if (32 <= c && c < 127)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int				index;
	unsigned char	current;

	index = 0;
	while (1)
	{
		current = str[index];
		if (current == '\0')
			break ;
		if (is_valid(current))
			ft_putchar(current);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[current / 16]);
			ft_putchar("0123456789abcdef"[current % 16]);
		}
		index++;
	}
}
