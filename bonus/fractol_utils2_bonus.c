/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:38:48 by kfergani          #+#    #+#             */
/*   Updated: 2022/08/04 04:57:57 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_info(t_mlx	*info)
{
	char	*s;

	info->zoom = 0.02;
	info->fixed_julia_c.i = 1.101176;
	info->fixed_julia_c.r = -0.004706;
	info->x_center = WIDTH / 2;
	info->y_center = HEIGHT / 2;
	info->x_move = 0;
	info->iter = 50;
	info->color_i = 10;
	info->color_r = 10;
	ft_printf("\t\tWelcom !\n");
	ft_printf("Choose the index of a fractol from the Menu(default 1):");
	ft_printf("\n1-Mandelbrot\n2-Julia\n3-Mystery-Box\n");
	s = get_next_line(0);
	info->fractol = ft_atoi(s);
	if (!info->fractol || info->fractol < 1 || info->fractol > 3)
	{
		ft_printf("Invalid choice!\n");
		if (s)
			free(s);
		exit(1);
	}
	if (s)
		free(s);
}

int	get_mandlbrot_julia(t_mlx *info, t_matrix m)
{
	t_complex	c;
	t_complex	z;
	int			i;

	c = get_complex(m, info);
	if (info->active_colors)
		z = info->julia_c;
	else
		z = info->fixed_julia_c;
	if (info->fractol == 1)
		z = c;
	i = 0;
	while (i++ < info->iter && (c.i * c.i + c.r * c.r) < 4)
		c = get_next(c, z);
	return (i);
}

int	get_bonus(t_mlx *info, t_matrix m)
{
	t_complex	c;
	t_complex	z;
	int			i;

	c = get_complex(m, info);
	if (info->active_colors)
		z = info->julia_c;
	else
		z = info->fixed_julia_c;
	i = 0;
	while (i++ < info->iter && (c.i * c.i + c.r * c.r) < 4)
		c = get_next_bonus(c, z);
	return (i);
}
