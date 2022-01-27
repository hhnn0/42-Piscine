/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:24:15 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/24 19:53:49 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	is_valid(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1 || str == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		if (str[i] == '+' || str[i] == '-' || str[i] < 32 || str[i] > 126)
		{
			return (0);
		}
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	blen;

	if (!is_valid(base))
		return ;
	blen = ft_strlen(base);
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / blen, base);
		ft_putchar(base[-(nbr % blen)]);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
		return ;
	}
	if (nbr > blen - 1)
		ft_putnbr_base(nbr / blen, base);
	ft_putchar(base[nbr % blen]);
}
