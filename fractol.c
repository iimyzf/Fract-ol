/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:19:20 by mac               #+#    #+#             */
/*   Updated: 2022/03/01 18:35:52 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"

typedef struct s_z
{
    float   re;
    float   im;
}   t_z;


int main(void)
{
    void    *mlx;
    void    *win;
    int     i;
    int     j;
    int     n;
    float   temp;
    t_z     z;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 500, 500, "Mandelbrot Set");
    i = 0;
    while (i < 500)
    {
        j = 0;
        while (j < 500)
        {
            n = 0;
            z.re = 0;
            z.im = 0;
            while (n < 100 && z.re * z.re + z.im * z.im < 4)
            {
                temp = z.re;
                z.re = z.re * z.re - z.im * z.im + i * (4.f / 500) - 2.f;
                z.im = 2 * temp * z.im - j * (4.f / 500) + 2.f;
                n++;
            }
            if (n < 100)
                mlx_pixel_put(mlx, win, i, j, n * 0xffffff);
            j++;
        }
        i++;
    }
    mlx_loop(mlx);
}