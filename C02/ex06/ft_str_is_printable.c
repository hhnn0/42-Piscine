/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:46:30 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/18 17:33:07 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (32 <= str[i] && str[i] <= 126)
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
