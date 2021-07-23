/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 21:14:25 by naaghasy          #+#    #+#             */
/*   Updated: 2021/06/16 21:14:27 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_xpm_file_to_img(t_info *info, unsigned int **addr, char *file)
{
	int		fd;
	void	*img;
	int		tab[5];

	if (ft_check_name(file, "xpm") == 0)
		return (-1);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(info->mlx.ptr, file, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != 64 || tab[1] != 64)
		return (-1);
	*addr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	free(img);
	return (0);	
}

int		ft_add_resulation_to_info(t_info *info, char *width, char *height)
{
	if (info->win.width != 0 || info->win.height != 0)
		return (-3);
	info->win.width = ft_atoi(width);
	info->win.height = ft_atoi(height);
	if (info->win.width > 2560)
		info->win.width = 2560;
	if (info->win.height > 1400)
		info->win.height = 1400;
	if (info->win.width <= 0 || info->win.height <= 0)
		return (-4);
	return (1);
}

int		ft_add_color(char *type, char *value, t_info *info)
{
	char			**color_values;
	unsigned int	floor;
	unsigned int	ceilling;
	int				r;
	int				g;
	int				b;

	floor = info->texture.floor;
	ceilling = info->texture.ceilling;
	color_values = ft_split(value, ',');
	r = ft_atoi(color_values[0]);
	g = ft_atoi(color_values[1]);
	b = ft_atoi(color_values[2]);
	if (r > 256 || r > 256 || b > 256)
		return (-6);
	if ((floor != NONE && !ft_strcmp(type, "F")) ||
			(ceilling != NONE && !ft_strcmp(type, "F")))
		return (-5);
	if (ft_strcmp(type, "F"))
		info->texture.floor = r * pow(256, 2) + g * 256 + b;
	else if (ft_strcmp(type, "C"))
		info->texture.ceilling = r * pow(256, 2) + g * 256 + b;
	return (1);
}

int		ft_add_texture_to_info(t_info *info, char *path, char *type)
{
	int		xpm_res;

	xpm_res = 0;
	if (ft_strcmp(type, "NO") == 0)
		xpm_res = ft_xpm_file_to_img(info, &info->texture.no, path);
	else if (ft_strcmp(type, "SO") == 0)
		xpm_res = ft_xpm_file_to_img(info, &info->texture.so, path);
	else if (ft_strcmp(type, "EA") == 0)
		xpm_res = ft_xpm_file_to_img(info, &info->texture.ea, path);
	else if (ft_strcmp(type, "WE") == 0)
		xpm_res = ft_xpm_file_to_img(info, &info->texture.we, path);
	if (xpm_res == -1)
		return (-9);
	return (1);
}

int		ft_map_row_len(t_info *info, char *line)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[i++] != '\0')
	{
		if (ft_check_char(line[i], "NWES01 ") == 1)
			len++;
	}
	if (info->map.width != 0 && info->map.width != len)
		return (-1);
	return (len);
}

int		ft_check_map_row(t_info *info, char *line)
{
	t_list	*row;
	int		i;

	i = 0;
	row = ft_lstnew((void*)line);
	ft_lstadd_back(&info->map.board, row);
	// if (ft_strcmp(temp_map->content, "head") || temp_map->next == NULL)
	// {
	// 	while (line[i])
	// 	{
	// 		if (line[i] != '1')
	// 			return (-19);
	// 		i++;
	// 	}
	// }
	// if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
	// 	return (-19);
	return (1);
}

int		ft_map_to_info(t_info *info, char *line)
{
	int		i;
	int		j;
	int		map_len;
	char	*temp;
	
	j = 0;
	i = 0;
	map_len = ft_map_row_len(info, line);
	temp = malloc(sizeof(char) * map_len + 1);
	while (line[i] != '\0' && j <= map_len)
	{
		// printf("line[%d] = %c --- | condition value: %d\n", i, line[i], ft_check_char(line[i], "NWES01 "));
		if (ft_check_char(line[i], "NWES01 "))
		{
			temp[j] = line[i];
			j++;
		}
		else
			return (-13);
		i++;
	}
	return (ft_check_map_row(info, temp));
}

int		ft_check_type_of_line(char *line, t_info *info)
{
	char 	**splited_line;
	char 	*type;
	int		i;

	i = 0;
	splited_line = ft_split(line, ' ');
	type = NULL;
	ft_whitespace(line, &i);
	if (ft_str_arr_len(splited_line) < 1)
		return(0);
	type = splited_line[0];
	if (ft_check_str(type, "NO SO WE EA") == 1)
		info->err.n = ft_add_texture_to_info(info, splited_line[1], type);
	else if (ft_strcmp(type, "R") == 0)
		info->err.n = ft_add_resulation_to_info(info, splited_line[1], splited_line[2]);
	else if (ft_check_str(type, "F C"))
		info->err.n = ft_add_color(type, splited_line[1], info);
	else if (line[i] == '1')
	{
		info->map.height++;
		info->err.n = ft_map_to_info(info, line);
	}
	if (ft_whitespace(line, &i) && info->err.n == 0 && line[i] != '\0')
		ft_print_errors(-10);
	if (info->err.n < 0)
		ft_print_errors(info->err.n);
	return (0);
}

//Parsing checking function for me
void	ft_check_parsing(t_info *info) {
	t_list *tmp;

	tmp = info->map.board;
	printf("Resulation --- | width: %d | height: %d\n", info->win.width, info->win.height);
	printf("NO texture --- | path: %p\n", info->texture.no);
	printf("WE texture --- | path: %p\n", info->texture.we);
	printf("EA texture --- | path: %p\n", info->texture.ea);
	printf("SO texture --- | path: %p\n", info->texture.so);
	printf("F  color --- | color: %u\n", info->texture.floor);
	printf("C  color --- | color: %u\n", info->texture.ceilling);
	int j = 0;
	while(tmp->next)
	{
		printf("--- | %s |------ Map[%d]\n", (char*)tmp->next->content, j++);
		tmp = tmp->next;
	}
}
//

void	ft_position(t_info *info)
{
	char	**map;
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	map = ft_from_list_to_2darr(info->map.board);
	while (map[i] != '\0')
	{
		j = 0;
		c = map[i][j];
		while (map[i][j] != '\0')
		{
			if (ft_check_char(c, "NWSE"))
			{
				info->pos.y = (double)i + 0.5;
				info->pos.x = (double)j + 0.5;
				info->dir.x = (c == 'E' || c == 'W') ? 1 : 0;
				info->dir.x *= (c == 'W') ? -1 : 1;
				info->dir.y = (c == 'S' || c == 'N') ? 1 : 0;
				info->dir.y *= (c == 'N') ? -1 : 1;
				info->err.p++;
			}
			j++;
		}
		i++;
	}
}

int		ft_parse_dot_cub(t_info *info, char *cub)
{
	int		fd;
	int		readed;
	char 	*line;

	readed = 1;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		ft_print_errors(-1);
	while (readed == 1)
	{
		readed = get_next_line(fd, &line);
		ft_check_type_of_line(line, info);
		free(line);
	}
	close(fd);
	if (readed == -1 || readed == -3)
		return (ft_print_errors(readed + 1));
	// ft_check_parsing(info);
	ft_position(info);
	// printf("Hello\n");
	char **temp = ft_from_list_to_2darr(info->map.board);
	// (void)temp;
	for(int i = 0; i < ft_str_arr_len(temp); i++) {
		printf("%s ---- %d\n", temp[i], i);
	}
	// printf("ft_parse_dot_cub is done!!!\n");
	return (1);
}
