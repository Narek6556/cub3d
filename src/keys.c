/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:33:39 by naaghasy          #+#    #+#             */
/*   Updated: 2021/05/18 17:33:41 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


//map-y free anely petqa poxvi
int     ft_close(t_info *info, int win)
{
    int     i;

    i = 0;
    while (i < info->map.height)
        free(info->map.board);
    free(info->map.board);
    free(info->texture.no);
    free(info->texture.we);
    free(info->texture.so);
    free(info->texture.ea);
    if (win == 1)
        mlx_destroy_window(info->mlx.ptr, info->win.ptr);
    free(info->mlx.ptr);
    exit(0);
    return (1);
}

//logikan poxvuma
void    ft_move_forward_backward(t_info *info, int dir)
{
    char    **map;

    map = ft_from_list_to_2darr(info->map.board);
    info->pos.x += dir * (info->dir.x * 15) / 100;
    if (map[(int)floor(info->pos.y)][(int)floor(info->pos.x)] == '1')
        info->pos.x -= dir * (info->dir.x * 15) / 100;
    info->pos.y += dir * (info->dir.y * 15) / 100;
    if (map[(int)floor(info->pos.y)][(int)floor(info->pos.x)] == '1')
        info->pos.y -= dir * (info->dir.y * 15) / 100;
    // if (info->map.board[(int)floor(info->pos.y)][(int)floor(info->pos.x)] == '2')
    // {
    //     info->map.board[(int)floor(info->pos.y)][(int)floor(info->pos.x)] = '0';
    //     info->map.sprite--;
    //     ft_sprite_list(info);
    // }
}

void    ft_move_left_right(t_info *info, int dir)
{
    char    **map;

    map = ft_from_list_to_2darr(info->map.board);
    info->pos.x += dir * (info->dir.y * 15) / 100;
    if (map[(int)floor(info->pos.y)][(int)floor(info->pos.x)] == '1')
        info->pos.x -= dir * (info->dir.y * 15) / 100;
    info->pos.y += dir * (info->dir.x * 15) / 100;
    if (map[(int)floor(info->pos.y)][(int)floor(info->pos.x)] == '1')
        info->pos.y -= dir * (info->dir.x * 15) / 100;
    // if (info->map.board[(int)floor(info->pos.y)][(int)floor(info->pos.x)] == '2')
    // {
    //     info->map.board[(int)floor(info->pos.y)][(int)floor(info->pos.x)] = '0';
    //     info->map.sprite--;
    //     ft_sprite_list(info);
    // }
}

void    ft_rotate(t_info *info, int dir)
{
    double	dist;

	info->dir.x = info->dir.x * cos(dir * 0.05) - info->dir.y * sin(dir * 0.05);
	info->dir.y = info->dir.y * cos(dir * 0.05) + info->dir.x * sin(dir * 0.05);
	dist = hypot(info->dir.x, info->dir.y);
	info->dir.x /= dist;
	info->dir.y /= dist;
}

int     ft_key(int key, void *arg)
{
    if (key == ESC)
        ft_close(arg, 1);
    else if (key == W)
        ft_move_forward_backward(arg, 1);
    else if (key == S)
        ft_move_forward_backward(arg, -1);
    else if (key == A)
        ft_move_left_right(arg, 1);
    else if (key == D)
        ft_move_left_right(arg, -1);
    else if (key == LEFT)
        ft_rotate(arg, 1);
    else if (key == RIGHT)
        ft_rotate(arg, -1);
    ft_draw(arg);
    return (1);
}
