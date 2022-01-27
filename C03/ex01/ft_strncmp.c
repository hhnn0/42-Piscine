/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:06:39 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/17 14:57:23 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j] && i < n - 1 )
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}
