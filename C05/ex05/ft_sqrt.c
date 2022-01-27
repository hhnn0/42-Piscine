/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <hyunhkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:18:44 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/23 11:14:41 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	result;
	unsigned int	num;

	num = 0;
	if (nb <= 0)
		return (0);
	while ((num * num) <= (unsigned int)nb)
		num++;
	num--;
	result = num * num;
	if (result == (unsigned int)nb)
		return (num);
	else
		return (0);
}
