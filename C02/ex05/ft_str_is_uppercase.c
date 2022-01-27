/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:44:39 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/18 17:32:42 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			if (str[++i] == '\0')
			{
				return (1);
			}
		}
		else
		{
			return (0);
		}
	}
	if (i == 0)
	{
		return (1);
	}
	return (0);
}
