/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:57:55 by yagnaou           #+#    #+#             */
/*   Updated: 2022/03/09 17:27:54 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_ship(t_p *p)
{
	p->c_re = (p->i - WIN_SIZE / 2.0) * p->zoom / WIN_SIZE + p->x;
	p->c_im = (p->j - WIN_SIZE / 2.0) * p->zoom / WIN_SIZE + p->y;
	while (p->n < 100 && p->re * p->re + p->im * p->im < 4)
	{
		p->temp = p->re * p->re - p->im * p->im + p->c_re;
		p->im = fabs(2 * p->re * p->im) + p->c_im;
		p->re = p->temp;
		p->n++;
	}
	return (p->n);
}

void	burning_ship(t_p *p)
{
	p->i = 0;
	while (p->i < WIN_SIZE)
	{
		p->j = 0;
		while (p->j < WIN_SIZE)
		{
			p->n = 0;
			p->re = 0;
			p->im = 0;
			if (p->n < 100)
				my_putpixel(p, p->i, p->j, iterate_ship(p) * 0xff0000);
			p->j++;
		}
		p->i++;
	}
}
