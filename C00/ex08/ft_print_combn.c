/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.422seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:30:54 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/13 16:31:29 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putcomma(int n, int *arr)
{
	if (arr[0] != 10 - n || arr[n - 1] != 9)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	dfs(int depth, int start, int n, int *arr)
{
	int	i;
	int	j;

	i = 0;
	j = start;
	if (depth == n)
	{
		while (i < n)
		{
			ft_putchar(arr[i] + 48);
			i++;
		}
		ft_putcomma(n, arr);
	}
	else
	{
		while (j < 10)
		{
			arr[depth] = j;
			dfs(depth + 1, j + 1, n, arr);
			j++;
		}
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	dfs(0, 0, n, arr);
}
