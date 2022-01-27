/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:56:44 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/20 16:58:39 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	t_len;
	int	s_len;
	int	i;

	t_len = 0;
	s_len = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		t_len += ft_strlen(strs[i]);
		t_len += s_len;
		i++;
	}
	t_len -= s_len;
	return (t_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		t_len;
	int		i;
	char	*head;
	char	*total;

	t_len = ft_total_len(size, strs, sep);
	total = (char *)malloc((t_len + 1) * sizeof(char));
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	if (total == 0)
		return (0);
	head = total;
	i = -1;
	while (++i < size)
	{
		ft_strcpy(head, strs[i]);
		head += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(head, sep);
			head += ft_strlen(sep);
		}
	}
	head[i] = '\0';
	return (total);
}
