/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:24:01 by sel-jett          #+#    #+#             */
/*   Updated: 2024/01/02 20:19:30 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	angle_z(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.7);
	*y = (*y + *x) * sin(0.7) - z;
}
void	ft_bresenham(void *mlx, void *mlx_win, int x1, int y1, int x2, int y2, int z)
{
	int	dx;
	int	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dy) < abs(dx))
	{
		if (x1 > x2)
			plotline_low(mlx, mlx_win, x2, y2, x1, y1, z);
		else
			plotline_low(mlx, mlx_win, x1, y1, x2, y2, z);
	}
	else
	{
		if (y1 > y2)
			plotline_high(mlx, mlx_win, x2, y2, x1, y1, z);
		else
			plotline_high(mlx, mlx_win, x1, y1, x2, y2, z);
	}
}

void	plotline_low(void *mlx, void *mlx_win, int x1, int y1, int x2, int y2, int z)
{
	int	dx;
	int	yi;
	int	dy;
	int	x;
	int	y;
	int	p;
	int rem;
	int rem2;

	yi = 1;
	x = x1;
	y = y1;
	dx = x2 - x;
	dy = y2 - y;
	if (dy < 0)
	{
		yi = -1;
		dy *= -1;
	}
	p = (2 * dy) - dx;
	while (x <= x2)
	{
		rem = x;
		rem2 = y;
		angle_z(&x, &y , z);
		mlx_pixel_put(mlx, mlx_win, x, y, 0xFFFFFF);
		x = rem;
		y = rem2;
		if (p > 0)
		{
			y += yi;
			p = p + (2 * (dy - dx));
		}
		else
			p = p + (2 * dy);
		x++;
	}
}

void	plotline_high(void *mlx, void *mlx_win, int x1, int y1, int x2, int y2, int z)
{
	int	x;
	int	dx;
	int	y;
	int	xi;
	int	dy;
	int	p;
	int rem;
	int rem2;

	xi = 1;
	x = x1;
	y = y1;
	dx = x2 - x;
	dy = y2 - y;
	if (dx < 0)
	{
		xi = -1;
		dx *= -1;
	}
	p = (2 * dx) - dy;
	while (y <= y2)
	{
		rem = x;
		rem2 = y;
		angle_z(&x, &y , z);
		mlx_pixel_put(mlx, mlx_win, x, y, 0xFF00FF);
		x = rem;
		y = rem2;
		if (p > 0)
		{
			x = x + xi;
			p = p + (2 * (dx - dy));
		}
		else
			p = p + (2 * dx);
		y++;
	}
}

int	main (int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_neox	*neox;
	int		count;
	int		x;
	int		y;

	neox = NULL;
	mlx = mlx_init();
	ft_check_args(ac, av);
	count = ft_parser(&neox, av);
	mlx_win = mlx_new_window(mlx, 1480, 900, "Hello world");
	y = -1;
	while (neox)
	{
		x = -1;
		++y;
		while(++x <= count)
		{
				if (x < count)
				{
					ft_bresenham(mlx, mlx_win, ((x  + 17) * 35), ((y  + 2) * 35), (((x  + 17) + 1) * 35), (((y  + 2)) * 35), neox->line[x][0]);
					ft_bresenham(mlx, mlx_win, ((x  + 17) * 35), ((y + 2) * 35), (((x  + 17)) * 35), (((y  + 2) + 1) * 35), neox->line[x][0]);
				}
				else
					ft_bresenham(mlx, mlx_win, ((x  + 17) * 35), ((y + 2) * 35), (((x  + 17)) * 35), (((y  + 2) + 1) * 35), 20);

		}
		neox = neox->next;
	}
	x = -1;
	y++;
	while (++x < count)
		ft_bresenham(mlx, mlx_win, ((x + 17) * 35), ((y + 2) * 35), (((x + 17) + 1) * 35), (((y + 2)) * 35), 20);
	mlx_loop(mlx);
	my_malloc(0, 2);
}
