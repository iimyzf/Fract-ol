/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:35:44 by yagnaou           #+#    #+#             */
/*   Updated: 2022/03/09 17:38:18 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_putpixel(t_p *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	arrow_move(int keycode, t_p *p)
{
	if (keycode == ESC_KEY)
		exit(EXIT_FAILURE);
	if (keycode == LEFT_KEY)
		p->x += 0.1;
	if (keycode == RIGHT_KEY)
		p->x -= 0.1;
	if (keycode == UP_KEY)
		p->y += 0.1;
	if (keycode == DOWN_KEY)
		p->y -= 0.1;
	mlx_clear_window(p->ptr, p->win);
	if (!ft_strcmp(p->fractal, "julia") || !ft_strcmp(p->fractal, "first_julia")
		|| !ft_strcmp(p->fractal, "second_julia"))
		julia(p->fractal, p);
	if (!ft_strcmp(p->fractal, "mandelbrot"))
		mandelbrot(p);
	if (!ft_strcmp(p->fractal, "burning_ship"))
		burning_ship(p);
	mlx_put_image_to_window(p->ptr, p->win, p->img, p->x, p->y);
	return (0);
}

int	zoom(int keycode, int x, int y, t_p *p)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_DOWN || keycode == MOUSE_UP)
	{
		if (keycode == MOUSE_DOWN)
			p->zoom /= 0.8;
		else
			p->zoom *= 0.8;
	}
	mlx_clear_window(p->ptr, p->win);
	if (!ft_strcmp(p->fractal, "julia") || !ft_strcmp(p->fractal, "first_julia")
		|| !ft_strcmp(p->fractal, "second_julia"))
		julia(p->fractal, p);
	if (!ft_strcmp(p->fractal, "mandelbrot"))
		mandelbrot(p);
	if (!ft_strcmp(p->fractal, "burning_ship"))
		burning_ship(p);
	mlx_put_image_to_window(p->ptr, p->win, p->img, 0, 0);
	return (0);
}
