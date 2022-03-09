/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:18:49 by yagnaou           #+#    #+#             */
/*   Updated: 2022/03/09 17:23:37 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_julia(char *av, t_p *p)
{
	if (!ft_strcmp(av, "first_julia"))
	{
		p->c_re = -0.2321;
		p->c_im = -0.835;
	}
	else if (!ft_strcmp(av, "second_julia"))
	{
		p->c_re = -0.3842;
		p->c_im = -0.70176;
	}
	else
	{
		p->c_re = 0.01;
		p->c_im = 0.285;
	}
	while (p->n < 100 && p->re * p->re + p->im * p->im < 4)
	{
		p->temp = p->re * p->re - p->im * p->im;
		p->im = 2 * p->re * p->im + p->c_re;
		p->re = p->temp + p->c_im;
		p->n++;
	}
	return (p->n);
}

void	julia(char *av, t_p *p)
{
	p->i = 0;
	while (p->i < WIN_SIZE)
	{
		p->j = 0;
		while (p->j < WIN_SIZE)
		{
			p->n = 0;
			p->re = (p->i - WIN_SIZE / 2) * (p->zoom / WIN_SIZE) + p->x;
			p->im = (p->j - WIN_SIZE / 2) * (p->zoom / WIN_SIZE) + p->y;
			if (p->n < 100)
				my_putpixel(p, p->i, p->j, iterate_julia(av, p) * 0xff0000);
			p->j++;
		}
		p->i++;
	}
}
