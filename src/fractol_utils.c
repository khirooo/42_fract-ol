/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 03:08:57 by kfergani          #+#    #+#             */
/*   Updated: 2022/08/04 02:34:11 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	fatoi(char *s)
{
	double	f;
	double	i;
	double	len;

	if (!s)
		return (0.5);
	i = ft_atoi(s);
	while (*s && *s != '.')
		s++;
	if (*s)
		s++;
	f = ft_atoi(s);
	len = 10;
	while (f / 10 > 1)
	{
		f /= 10;
		len = len * 10;
	}
	f = ft_atoi(s);
	return (i + (f / len));
}

t_complex	get_complex(t_matrix m_cord, t_mlx *info)
{
	t_complex	c_cord;

	c_cord.i = (WIDTH / 2 - (double)m_cord.j + info->x_move)
		* 4 / (HEIGHT * info->zoom * 50);
	c_cord.r = -(HEIGHT / 2 - (double)m_cord.i + info->y_move)
		* 4 / (WIDTH * info->zoom * 50);
	return (c_cord);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

t_complex	get_next(t_complex c, t_complex z)
{
	t_complex	c2;

	c2.r = c.r * c.r - c.i * c.i + z.r;
	c2.i = 2 * c.r * c.i + z.i;
	return (c2);
}
