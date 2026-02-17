/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbentham <jbentham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:22:32 by jbentham          #+#    #+#             */
/*   Updated: 2026/02/17 22:08:57 by jbentham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libftprintf/ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	sum;
	int	digit;

	i = 0;
	sign = 1;
	sum = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		digit = nptr[i] - '0';
		check_overflow(sum, digit, sign);
		sum = (sum * 10) + digit;
		i++;
	}
	return (sign * sum);
}

void	check_overflow(int sum, int digit, int sign)
{
	if (sign == 1 && sum > (INT_MAX - digit) / 10)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (sign == -1 && sum > ((long)INT_MAX + 1 - digit) / 10)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
