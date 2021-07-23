/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:32:01 by naaghasy          #+#    #+#             */
/*   Updated: 2021/06/15 12:32:03 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw(t_info *info)
{
	info->ray.x = 0;
	info->ray.y = 0;
	info->ray.i = 0;
	info->ray.v = 0;
	info->ray.w = 0;
	info->hit.x = 0;
	info->hit.y = 0;
	info->hit.d = 0;
	ft_screen(info);
	mlx_put_image_to_window(info->mlx.ptr, info->win.ptr, info->img.ptr, 0, 0);
	free(info->img.ptr);
	free(info->img.addr);
}

int		ft_adding_new_window(t_info *info, char *cub)
{
	int		width;
	int		height;

	info->pos.x = 0;
	info->pos.y = 0;
	info->dir.x = 0;
	info->dir.y = 0;
	info->mlx.ptr = mlx_init();
	ft_parse_dot_cub(info, cub);
	width = info->win.width;
	height = info->win.height;
	info->win.ptr = mlx_new_window(info->mlx.ptr, width, height, "cub3d");
	ft_draw(info);
	mlx_hook(info->win.ptr, 2, 0, ft_key, info);
	mlx_hook(info->win.ptr, 17, 0, ft_close, info);
	mlx_loop(info->mlx.ptr);
	return (1);
}

void	ft_game_init(t_info *info, char *cub)
{
	info->mlx.ptr = NULL;
	info->win.ptr = NULL;
	info->win.width = 0;
	info->win.height = 0;
	info->img.ptr = NULL;
	info->img.addr = NULL;
	info->img.fsh = 0;
	info->err.m = 0;
	info->err.n = 0;
	info->err.p = 0;
	info->map.board = ft_lstnew("head");
	info->map.height = 0;
	info->map.width = 0;
	info->texture.no = NULL;
	info->texture.so = NULL;
	info->texture.we = NULL;
	info->texture.ea = NULL;
	info->texture.ceilling = NONE;
	info->texture.floor = NONE;
	info->stk = NULL;
	ft_adding_new_window(info, cub);
}

int		main(int ac, char **av)
{
	t_info		*info;

	info = NULL;
	info = malloc(sizeof(t_info) + 1);
	if (ac == 2 && ft_check_name(av[1], "cub"))
        ft_game_init(info, av[1]);
    else
        printf("%s\n", "Error: Invalid arguments");
	return (0);
}
