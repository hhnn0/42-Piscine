/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countbox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:51:35 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/16 20:51:39 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_view_ok(int map[][4], t_MaxSeeBox see_box)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (
			!(view_from_right(i, map) == see_box.right[i]
				&& view_from_left(i, map) == see_box.left[i]
				&& view_from_up(i, map) == see_box.up[i]
				&& view_from_down(i, map) == see_box.down[i])
		)
			return (0);
		i++;
	}
	return (1);
}

int	view_from_down(int col, int map[][4])
{
	int	r;
	int	max;
	int	box_num;

	r = 3;
	max = 0;
	box_num = 0;
	while (r >= 0)
	{
		if (map[r][col] > max)
		{
			max = map[r][col];
			box_num++;
		}
		r--;
	}
	return (box_num);
}

int	view_from_up(int col, int map[][4])
{
	int	r;
	int	max;
	int	box_num;

	r = 0;
	max = 0;
	box_num = 0;
	while (r < 4)
	{
		if (map[r][col] > max)
		{
			max = map[r][col];
			box_num++;
		}
		r++;
	}
	return (box_num);
}

int	view_from_left(int row, int map[][4])
{
	int	c;
	int	max;
	int	box_num;

	c = 0;
	max = 0;
	box_num = 0;
	while (c < 4)
	{
		if (map[row][c] > max)
		{
			max = map[row][c];
			box_num++;
		}
		c++;
	}
	return (box_num);
}

int	view_from_right(int row, int map[][4])
{
	int	c;
	int	max;
	int	box_num;

	c = 3;
	max = 0;
	box_num = 0;
	while (c >= 0)
	{
		if (map[row][c] > max)
		{
			max = map[row][c];
			box_num++;
		}
		c--;
	}
	return (box_num);
}
