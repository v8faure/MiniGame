/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:20:01 by slonnie           #+#    #+#             */
/*   Updated: 2022/04/05 17:14:28 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s1 == 0 || s2 == 0)
		return (0);
	k = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s3 = (char *)malloc((i + j + 1) * sizeof(char));
	if (NULL == s3)
		return (0);
	while (i--)
	{
		s3[k] = *s1++;
		k++;
	}
	while (j--)
	{
		s3[k] = *s2++;
		k++;
	}
	s3[k] = '\0';
	return (s3);
}
