/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:52:08 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/16 20:52:09 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
typedef struct t_MaxSeeBox {
	int	up[4];
	int	down[4];
	int	left[4];
	int	right[4];
}	t_MaxSeeBox;

int		view_from_down(int col, int map[][4]);
int		view_from_up(int col, int map[][4]);
int		view_from_left(int col, int map[][4]);
int		view_from_right(int col, int map[][4]);
int		is_view_ok(int map[][4], t_MaxSeeBox see_box);

int		rush(t_MaxSeeBox see_box);
#endif
