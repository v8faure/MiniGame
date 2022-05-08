/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slonnie <slonnie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:49:04 by slonnie           #+#    #+#             */
/*   Updated: 2022/04/09 00:15:35 by slonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char chr, int fd)
{
	if ((write(fd, &chr, 1) < 0))
		exit(EXIT_FAILURE);
}

void	ft_putstr_fd(char *msg, int fd)
{
	while (*msg)
	{
		if ((write(fd, msg++, 1)) < 0)
			exit(EXIT_FAILURE);
	}
}

void	print_error_and_exit(char *err_msg)
{
	ft_putstr_fd("Error - ", STDERR_FILENO);
	if (err_msg)
		ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}
