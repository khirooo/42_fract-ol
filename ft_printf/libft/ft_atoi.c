/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:56 by kfergani          #+#    #+#             */
/*   Updated: 2022/07/20 21:34:19 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - 48);
		if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
		{
			write(1, "Error3\n", 6);
			exit (1);
		}
		str++;
	}
	return (num * sign);
}
