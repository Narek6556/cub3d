/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:28:15 by naaghasy          #+#    #+#             */
/*   Updated: 2021/05/28 15:28:16 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	ft_find_color(t_info *info, double i)
{
	int		j;

	if (floor(info->hit.y) == info->hit.y)
	{
		j = 64 * floor(64 * i) + 64 * (info->hit.x - floor(info->hit.x));
		if (info->ray.w == 1)
			return (info->texture.so[j]);
		else if (info->ray.w == 0)
			return (info->texture.no[j]);
	}
	else if (floor(info->hit.x) == info->hit.x)
	{
		j = 64 * floor(64 * i) + 64 * (info->hit.y - floor(info->hit.y));
		if (info->ray.v == 1)
			return (info->texture.ea[j]);
		else if (info->ray.v == 0)
			return (info->texture.we[j]);
	}
	return (0x00000000);
}

void			ft_wall(t_info *info, int size)
{
	unsigned int	color;
	int				start;
	int				count;

	start = info->win.width * (info->win.height - size) / 2;
	if (size > info->win.width)
		count = (size - info->win.width) / 2;
	else
		count = 0;
	color = info->texture.ceilling;
	while (info->ray.i < info->win.width * info->win.height)
	{
		if (info->ray.i >= start && count < size)
		{
			color = ft_find_color(info, (double)count / size);
			count++;
		}
		else if (count == size)
			color = info->texture.floor;
		info->img.addr[info->ray.i] = mlx_get_color_value(info->mlx.ptr, color);
		info->ray.i += info->win.width;
	}
	info->ray.i -= info->win.width * info->win.height;
}

int				ft_size(t_info *info)
{
	double		fisheye;
	double		correction;
	int			size;

	fisheye = fabs((double)info->ray.i / (info->win.width / 2) - 1);
	fisheye *= 28 * M_PI / 180;
	correction = (double)info->hit.d * cos(fisheye);
	size = round(info->win.height / correction);
	return (size);
}

void			ft_stock(t_info *info)
{
	info->stk[info->ray.i].x = info->ray.x;
	info->stk[info->ray.i].y = info->ray.y;
	info->stk[info->ray.i].d = info->hit.d;
}
