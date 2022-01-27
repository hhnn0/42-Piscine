/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:51:44 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/16 20:51:45 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "rush.h"

int	assert_and_assign(char *input, int range, int *arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < range)
	{
		if (i % 2 == 0)
		{
			if (input[i] < '1' || input[i] > '4')
				return (0);
			else
			{
				arr[j] = input[i] - 48;
				j++;
			}
		}
		else
		{
			if (input[i] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

t_MaxSeeBox	create_see_box(int index, int *arr)
{
	t_MaxSeeBox	see_box;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < index)
	{
		if (i < 4)
			see_box.up[j] = arr[i];
		else if (i < 8)
			see_box.down[j - 4] = arr[i];
		else if (i < 12)
			see_box.left[j - 8] = arr[i];
		else
			see_box.right[j - 12] = arr[i];
		i++;
		j++;
	}
	return (see_box);
}	

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	main(int ac, char **av)
{
	t_MaxSeeBox	see_box;
	int			arr[16];

	if (ac == 2)
	{
		if (!(ft_strlen(av[1]) == 31 && assert_and_assign(av[1], 31, arr)))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		see_box = create_see_box(16, arr);
		if (!rush(see_box))
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}
