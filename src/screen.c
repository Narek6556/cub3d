/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:32:32 by naaghasy          #+#    #+#             */
/*   Updated: 2021/05/27 18:32:34 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_ray(t_info *info)
{
    double      angle;
    double      distance;

    angle = ((double)info->ray.i - (info->win.width / 2)) * 33 / (info->win.width / 2);
    angle = angle * M_PI / 180;
    info->ray.x = info->dir.x * cos(angle) - info->dir.y * sin(angle);
    info->ray.y = info->dir.y * cos(angle) + info->dir.x * sin(angle);
    distance = hypot(info->ray.x, info->ray.y);
    info->ray.x /= distance;
    info->ray.y /= distance;
}

void    ft_direction(t_info *info)
{
    if (info->ray.x >= 0)
        info->ray.v = 1;
    else
        info->ray.v = 0;
    if (info->ray.y >= 0)
        info->ray.w = 1;
    else
        info->ray.w = 0;
}

//poxvuma map-y
void	ft_vertical(t_info *info)
{
    double  x;
    double  y;
    char    **map;

    map = ft_from_list_to_2darr(info->map.board);
    x = floor(info->pos.x) + info->ray.v;
    y = info->pos.y + (x - info->pos.x) * (info->ray.y / info->ray.x);
    while ((int)floor(y) > 0 && (int)floor(y) < info->map.height)
    {
        if (map[(int)floor(y)][(int)(x - 1 + info->ray.v)] == '1')
        {
            info->hit.x = x;
            info->hit.y = y;
            info->hit.d = hypot(x - info->pos.x, y - info->pos.y);
            return ;
        }
        x += (2 * info->ray.v - 1);
        y += (2 * info->ray.v - 1) * info->ray.y / info->ray.x;
    }
    info->hit.x = info->pos.x;
    info->hit.y = info->pos.y;
    info->hit.d = 1000000000;
}

//poxvuma map-i board-y
void    ft_horizontal(t_info *info)
{
    double  x;
    double  y;
    char    **map;

    map = ft_from_list_to_2darr(info->map.board);
    y = floor(info->pos.y) + info->ray.w;
    x = info->pos.x + (y - info->pos.y) * (info->ray.x / info->ray.y);
    while ((int)floor(x) > 0 && (int)floor(x) < info->map.width)
    {
        if (map[(int)(y - 1 + info->ray.w)][(int)floor(x)] == '1')
        {
            if (info->hit.d > hypot(x - info->pos.x, y - info->pos.y))
            {
                info->hit.x = x;
                info->hit.y = y;
                info->hit.d = hypot(x - info->pos.x, y - info->pos.y);
            }
            return ;
        }
        y += (2 * info->ray.w - 1);
        x += (2 * info->ray.w - 1) * info->ray.x / info->ray.y;
    }
}

void    ft_screen(t_info *i)
{
    int     b;
    int     s;
    int     e;

    i->img.ptr = mlx_new_image(i->mlx.ptr, i->win.width, i->win.height);
    i->img.addr = (unsigned int *)mlx_get_data_addr(i->img.ptr, &b, &s, &e);
    i->stk = malloc(sizeof(t_stk) * i->win.width);
    while (i->ray.i < i->win.width)
    {
        ft_ray(i);
        ft_direction(i);
        ft_vertical(i);
        ft_horizontal(i);
        ft_stock(i);
        ft_wall(i, ft_size(i));
        i->ray.i++;
    }
}
