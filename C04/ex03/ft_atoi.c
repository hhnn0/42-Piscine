/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:47:35 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/19 14:55:51 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	is_operator(char c)
{
	if (c == '+' || c == '-')
	{
		return (1);
	}
	return (0);
}

int	is_num(char c)
{
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	negative;
	int	result;

	i = 0;
	negative = 1;
	result = 0;
	while (is_space(str[i]))
	{
		i++;
	}
	while (is_operator(str[i]))
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (is_num(str[i]))
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * negative);
}
