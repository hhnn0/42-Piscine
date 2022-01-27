/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2022/01/17 17:41:03 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/22 12:40:31 by hyunhkim         ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	is_valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) <= 1 || str == 0)
		return (0);
	while (str[i] != '\0')
	{
		j = i + 1;
		if (str[i] == '+' || str[i] == '-' || is_space(str[i]))
		{
			return (0);
		}
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_counter(char *base, char counter)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == counter)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	negative;
	int	result;

	i = 0;
	negative = 1;
	result = 0;
	if (!is_valid(base))
		return (0);
	while (is_space(str[i++]))
		;
	i--;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (find_counter(base, str[i]) != -1)
	{
		result *= ft_strlen(base);
		result += find_counter(base, str[i]);
		i++;
	}
	return (result * negative);
}
