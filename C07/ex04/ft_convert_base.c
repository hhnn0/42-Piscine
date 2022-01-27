/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:13:57 by hyunhkim          #+#    #+#             */
/*   Updated: 2022/01/26 11:45:48 by hyunhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str);

int	is_valid(char *str);

unsigned int	ft_abs(int nbr)
{
	if (nbr < 0)
	{
		return (((unsigned int)nbr) * -1);
	}
	else
		return (nbr);
}

int	find_len(long long nbr, char *base)
{
	int			len;
	long long	blen;

	len = 0;
	blen = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= blen;
		len++;
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base, char *arr, int len)
{
	unsigned int	n;
	int				i;
	int				blen;

	if (nbr == 0)
	{
		arr[0] = base[0];
		return ;
	}
	blen = ft_strlen(base);
	n = ft_abs(nbr);
	if (nbr < 0)
		arr[len - 1] = '-';
	i = 0;
	while (n)
	{
		arr[i] = base[n % (unsigned int)blen];
		n = n / (unsigned int)blen;
		i++;
	}
}

char	*ft_strrev(char *str, int size)
{
	int		i;
	char	tmp;

	size--;
	i = 0;
	while (i < size)
	{
		tmp = str[i];
		str[i] = str[size];
		str[size] = tmp;
		i++;
		size--;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		from_nbr;
	char	*arr;
	int		arr_len;

	if (!(is_valid(base_from)) || !(is_valid(base_to)))
		return (0);
	from_nbr = ft_atoi_base(nbr, base_from);
	arr_len = find_len(from_nbr, base_to);
	arr = malloc(sizeof(char) * (arr_len + 1));
	if (arr == NULL)
		return (NULL);
	ft_putnbr_base(from_nbr, base_to, arr, arr_len);
	ft_strrev(arr, arr_len);
	arr[arr_len] = '\0';
	return (arr);
}
