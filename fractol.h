/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:04:54 by yagnaou           #+#    #+#             */
/*   Updated: 2022/03/09 17:30:38 by yagnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define WIN_SIZE 800
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define ESC_KEY 53
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_p
{
	void	*ptr;
	void	*win;
	void	*img;
	float	x;
	float	y;
	float	re;
	float	im;
	float	temp;
	float	zoom;
	float	c_re;
	float	c_im;
	char	*addr;
	char	*fractal;
	int		j;
	int		n;
	int		i;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
}	t_p;

void	hooks(t_p *p);
void	mandelbrot(t_p *p);
void	error_phrase(void);
void	burning_ship(t_p *p);
void	create_image(t_p *p);
void	create_window(t_p *p);
void	julia(char *av, t_p *p);
void	choose_fractale(char *av, t_p *p);
void	my_putpixel(t_p *p, int x, int y, int color);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		iterate_ship(t_p *p);
int		exit_when_close(void);
int		iterate_mandelbrot(t_p *p);
int		ft_strcmp(char *s1, char *s2);
int		available_fractals(char **av);
int		iterate_julia(char *av, t_p *p);
int		arrow_move(int keycode, t_p *p);
int		zoom(int keycode, int x, int y, t_p *p);

#endif
