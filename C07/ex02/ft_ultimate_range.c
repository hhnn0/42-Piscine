/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:19:35 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/20 16:39:07 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*arr;
	int	bound;

	i = 0;
	bound = max - min;
	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	arr = (int *)malloc(sizeof(int) * bound);
	if (arr == NULL)
	{
		*range = 0;
		return (-1);
	}
	*range = arr;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (bound);
}
