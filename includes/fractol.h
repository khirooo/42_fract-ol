/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:31:35 by kfergani          #+#    #+#             */
/*   Updated: 2022/08/04 02:24:32 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include "ft_printf.h"

# define WIDTH 900
# define HEIGHT 900

typedef struct s_complex
{
	double	i;
	double	r;
}	t_complex;

typedef struct s_matrix
{
	int	i;
	int	j;
}	t_matrix;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	int			fractol;
	double		zoom;
	t_complex	fixed_julia_c;
	int			x_center;
	int			y_center;
	t_complex	last_mouse;
	int			x_move;
	int			y_move;
	t_complex	julia_c;
	int			active_colors;
	int			iter;
	double		color_r;
	double		color_i;
}	t_mlx;

double		fatoi(char *s);
void		init_info(t_mlx	*info);
int			get_mandlbrot_julia(t_mlx *info, t_matrix m);
int			get_bonus(t_mlx *info, t_matrix m);
t_complex	get_complex(t_matrix m_cord, t_mlx *info);
int			get_rgba(int r, int g, int b, int a);
t_complex	get_next_bonus(t_complex c, t_complex z);
t_complex	get_next(t_complex c, t_complex z);
#endif