/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:31:37 by naaghasy          #+#    #+#             */
/*   Updated: 2021/06/15 12:31:40 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

# define NONE 0xFF000000
// # define WHITE 0x00FFFFFF
// # define BLACK 0x00000000
// # define RED 0x00FF0000
// # define GREEN 0x0000FF00
// # define BLUE 0x000000FF
// # define MAGENTA 0x00FF00FF
// # define YELLOW 0x00FFFF00
// # define CYAN 0x0000FFFF

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 15
# define TURN 0.05

typedef	struct 	s_mlx
{
	void	*ptr;
}				t_mlx;

typedef struct 	s_win
{
	void	*ptr;
	int		width;
	int		height;
}				t_win;

typedef struct s_img
{
    void            *ptr;
    unsigned    int *addr;
    int             fsh;
}              t_img;

typedef struct s_err
{
    int         n;
    int         m;
    int         p;
}              t_err;

typedef struct s_texture
{
    unsigned int    *no;
    unsigned int    *so;
    unsigned int    *ea;
    unsigned int    *we;
    unsigned int    ceilling;
    unsigned int    floor;
}              t_texture;

typedef struct  s_map
{
    t_list     *board;
    int         height;
    int         width;
}              t_map;

typedef struct s_stk
{
    double     	x;
    double     	y;
    double		d;
}              t_stk;

typedef struct s_dir
{
    double     	x;
    double     	y;
    double		a;
}              t_dir;

typedef struct s_pos
{
    double     	x;
    double     	y;
}              t_pos;

typedef struct	s_ray
{
	double			x;
	double			y;
	int				i;
	double			v;
	double			w;
}				t_ray;

typedef struct	s_hit
{
	double			x;
	double			y;
	double			d;
}				t_hit;

typedef struct s_info
{
    t_mlx       mlx;
    t_win       win;
    t_img       img;
    t_err       err;
    t_map       map;
    t_stk       *stk;
    t_texture   texture;
    t_pos       pos;
    t_dir       dir;
    t_ray       ray;
    t_hit       hit;
}              t_info;

int     ft_print_errors(int err);
int     ft_whitespace(char *line, int *i);
int     ft_check_name(char *arg, char *name);
int     get_next_line(int fd, char **line);
int     ft_parse_dot_cub(t_info *info, char *cub);
int     ft_check_str(char *str, char *str2);
void    ft_game_init(t_info *info, char *cub);
int     ft_adding_new_window(t_info *info, char *cub);
int     ft_check_type_of_line(char *line, t_info *info);
int     ft_add_texture_to_info(t_info *info, char *path, char *type);
int     ft_add_color(char *type, char *value, t_info *info);
int     ft_add_resulation_to_info(t_info *info, char *width, char *height);
int     ft_xpm_file_to_img(t_info *info, unsigned int **addr, char *file);
int     ft_check_char(char c, char *value);
int     ft_strcmp(const char *s1, const char *s2);
int     ft_str_arr_len(char **arr);
char    **ft_from_list_to_2darr(t_list *map);
int     ft_close(t_info *info, int win);
void    ft_move_forward_backward(t_info *info, int dir);
void    ft_move_left_right(t_info *info, int dir);
void    ft_rotate(t_info *info, int dir);
int     ft_key(int key, void *arg);
void    ft_ray(t_info *info);
void    ft_direction(t_info *info);
void    ft_vertical(t_info *info);
void    ft_horizontal(t_info *info);
void    ft_screen(t_info *i);
void            ft_stock(t_info *info);
int             ft_size(t_info *info);
void            ft_wall(t_info *info, int size);
unsigned int    ft_find_color(t_info *info, double i);
void    ft_draw(t_info *info);

#endif
