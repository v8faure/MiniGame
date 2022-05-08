/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:11:34 by slonnie           #+#    #+#             */
/*   Updated: 2022/04/08 22:42:26 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_number(int n)
{
	int		i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		i;

	i = len_number(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	number = (char *)malloc(sizeof(char) * (i + 1));
	if (number == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		number[0] = '-';
	}
	number[i--] = '\0';
	while (n / 10 > 0)
	{
		number[i--] = (n % 10) + '0';
		n /= 10;
	}
	number[i] = (n % 10) + '0';
	return (number);
}
