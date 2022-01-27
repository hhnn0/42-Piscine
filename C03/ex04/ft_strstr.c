/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:12:12 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/17 15:22:11 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*result;
	int		i;
	int		j;
	int		find_len;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	find_len = ft_len(to_find);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			result = &str[i];
			while (to_find[j] != '\0' && str[i + j] == to_find[j])
			{
				j++;
			}
			if (j == find_len)
				return (result);
		}
		i++;
	}
	return (0);
}
