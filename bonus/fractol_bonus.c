/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:30:45 by kfergani          #+#    #+#             */
/*   Updated: 2022/08/04 04:58:15 by kfergani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*info;

	info = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(info->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		info->active_colors = !(info->active_colors);
		info->fixed_julia_c = info->julia_c;
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		info->x_move -= 20;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		info->x_move += 20;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		info->y_move += 20;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		info->y_move -= 20;
	if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
		info->iter -= 10;
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		info->iter += 10;
}

void	draw(void *parem)
{
	t_mlx		*info;
	t_matrix	m;
	int			i;

	info = parem;
	m.i = 0;
	while (m.i < WIDTH)
	{
		m.j = 0;
		while (m.j < HEIGHT)
		{
			if (info->fractol == 3)
				i = get_bonus(info, m);
			else
				i = get_mandlbrot_julia(info, m);
			mlx_put_pixel(info->g_img, m.i, m.j, get_rgba(-log2(i) * 255 / 7
					+ log2(info->color_r), info->color_i + info->color_r,
					log2(i) * 255 / 5 + log2(info->color_i), 255));
			m.j++;
		}
		m.i++;
	}
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_matrix	mcord;
	t_mlx		*info;
	t_complex	c;

	info = param;
	mlx_get_mouse_pos(info->mlx, &mcord.i, &mcord.j);
	if (ydelta < 0)
		info->zoom *= 2;
	else
		info->zoom /= 2;
	info->last_mouse = get_complex(mcord, info);
	draw(info);
}

void	my_movinghook(void *param)
{
	t_mlx		*info;
	t_matrix	m;

	info = param;
	mlx_get_mouse_pos(info->mlx, &m.i, &m.j);
	info->julia_c = get_complex(m, info);
	if (mlx_is_mouse_down(info->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		info->color_i = info->julia_c.i;
		info->color_r = info->julia_c.r;
	}
	draw(info);
}

int	main(int argc, char *argv[])
{
	t_mlx		info;
	char		*s;

	init_info(&info);
	if (info.fractol == 2)
	{
		ft_printf("Choose a value for Julia (default 0)\n");
		s = get_next_line(0);
		info.fixed_julia_c.i = fatoi(s);
		info.fixed_julia_c.r = info.julia_c.i;
		if (s)
			free(s);
	}
	info.mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!info.mlx)
		return (EXIT_FAILURE);
	info.g_img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
	draw(&info);
	mlx_key_hook(info.mlx, &my_keyhook, &info);
	mlx_scroll_hook(info.mlx, &my_scrollhook, &info);
	mlx_loop_hook(info.mlx, &my_movinghook, &info);
	mlx_image_to_window(info.mlx, info.g_img, 0, 0);
	mlx_loop(info.mlx);
	mlx_terminate(info.mlx);
	return (EXIT_SUCCESS);
}
