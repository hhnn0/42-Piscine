/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:28:52 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/18 17:35:20 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;
	int	diff;

	i = 0;
	diff = 'a' - 'A';
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] = str[i] - diff;
		}
		i++;
	}
	return (str);
}

char	*ft_strlowcase(char *str, int i)
{
	int	diff;

	diff = 'a' - 'A';
	if ('A' <= str[i] && str[i] <= 'Z')
	{
		str[i] = str[i] + diff;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strupcase(str);
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			ft_strlowcase(str, i + 1);
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			ft_strlowcase(str, i + 1);
		}
		else if ('0' <= str[i] && str[i] <= '9')
		{
			ft_strlowcase(str, i + 1);
		}
		i++;
	}
	return (str);
}
