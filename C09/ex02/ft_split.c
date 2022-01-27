/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:43:16 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/26 20:19:23 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	if (charset[i] == '\0' && c == '\0')
		return (1);
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	split_start(char before, char current, char *charset)
{
	if (is_sep(before, charset) && !is_sep(current, charset))
		return (1);
	return (0);
}

int	splits_num(char *str, char *charset)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && !is_sep(str[i], charset))
			num++;
		else if (split_start(str[i - 1], str[i], charset))
			num++;
		i++;
	}
	return (num);
}

int	*splits_len(char *str, char *charset)
{
	int	i;
	int	index;
	int	num;
	int	*len;

	i = 0;
	index = 0;
	num = splits_num(str, charset);
	len = (int *)malloc((num + 100) * sizeof(int));
	while (i < num + 100)
	{
		len[i] = 0;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset))
			len[index]++;
		else if (i != 0 && !is_sep(str[i - 1], charset))
			index++;
		i++;
	}
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	**splits;
	int		i;
	int		j;
	int		index;
	int		*len;

	splits = malloc((splits_num(str, charset) + 100) * sizeof(char *));
	i = -1;
	j = 0;
	index = 0;
	len = splits_len(str, charset);
	while (str[++i] != '\0')
	{
		if (!is_sep(str[i], charset))
		{
			if (i == 0 || split_start(str[i - 1], str[i], charset))
				splits[index] = malloc((len[index] + 100) * sizeof(char));
			splits[index][j] = str[i];
			splits[index][++j] = '\0';
		}
		else if (i != 0 && !is_sep(str[i - 1], charset) && ++index)
			j = 0;
	}
	splits[index + 1] = 0;
	return (splits);
}
