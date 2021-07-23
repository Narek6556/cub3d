/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naaghasy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:28:39 by naaghasy          #+#    #+#             */
/*   Updated: 2021/06/15 16:28:41 by naaghasy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int     ft_str_arr_len(char **arr)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (arr[i] != '\0')
    {
        while (arr[i][j] != '\0') {
            j++;
        }
        i++;
    }
    return (i);
}

int     ft_check_str(char *str, char *str2)
{
    char 	**str2_splited;
    int		i;

    str2_splited = ft_split(str2, ' ');
    i = 0;
    while (i < ft_str_arr_len(str2_splited)) {
        if (ft_strcmp(str, str2_splited[i]) == 0) {
            return (1);
        }
        i++;
    }
    return (0);
}

int     ft_strcmp(const char *s1, const char *s2)
 {
    int i;
 
    i = 0;
    while (s1[i] == s2[i] && s1[i] && s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
 }

int     ft_check_name(char *arg, char *name)
{
    int     arg_len;
    int     i;
    int     name_len;
    char    *arg_format;

    arg_format = ft_substr(arg, ft_strlen(arg) - 3, 9);
    i = 0;
    name_len = ft_strlen(name);
    arg_len = ft_strlen(arg);
    if (arg_len <= 4)
        return (0);
    while (i < name_len)
    {
        if (arg_format[i] != name[i])
            return (0);
        i++;
    }
    return (1);
}

int     ft_whitespace(char *line, int *i)
{
    while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
    || (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
        (*i)++;
    return (1);
}

int     ft_check_char(char c, char *value)
{
    int  i;

    i = 0;
    while ((size_t)i < ft_strlen(value))
    {
        if (c == value[i])
            return (1);
        i++;
    }
    return (0);
}

char	**ft_from_list_to_2darr(t_list *map)
{
	char	**temp_map;
	int		i;
	int		j;
    int     map_size;

	i = 0;
	j = 0;
    map_size = ft_lstsize(map);
    // printf("map_size: %d\n", map_size);
	temp_map = (char **)ft_calloc(map_size, sizeof(char **));
	while (map && i < map_size + 1)
	{
        
        if (ft_strcmp(map->content, "head") != 0)
		{
            // printf("%s  ---- in while %d -- - - %d\n", map->content, i, map_size);
            temp_map[i++] = ft_strdup(map->content);
        }
		map = map->next;
        // printf("done!!! next map is: %p\n", map);
	}
    // printf("function done!!!\n");
	return (temp_map);
}

int     ft_print_errors(int err)
{
    (err == -1) ? printf("%s\n", "Error : Couldn't open file (FD)") : 0;
    (err == -2) ? printf("%s\n", "Error : Couldn't parse file (GNL)") : 0;
    (err == -3) ? printf("%s\n", "Error : Resolution specified twice") : 0;
    (err == -4) ? printf("%s\n", "Error : Invalid resolution") : 0;
    (err == -5) ? printf("%s\n", "Error : Floor/ceiling specified twice") : 0;
    (err == -6) ? printf("%s\n", "Error : Invalid floor/ceiling line") : 0;
    (err == -7) ? printf("%s\n", "Error : Texture path specified twice") : 0;
    (err == -8) ? printf("%s\n", "Error : Malloc fail (texture path)") : 0;
    (err == -9) ? printf("%s\n", "Error : Invalid texture image") : 0;
    (err == -10) ? printf("%s\n", "Error : Invalid line in file") : 0;
    (err == -11) ? printf("%s\n", "Error : Malloc fail (map table") : 0;
    (err == -12) ? printf("%s\n", "Error : Invalid map") : 0;
    (err == -13) ? printf("%s\n", "Error : Map isn't valid") : 0;
    (err == -14) ? printf("%s\n", "Error : No resolution specified") : 0;
    (err == -15) ? printf("%s\n", "Error : Missing texture") : 0;
    (err == -16) ? printf("%s\n", "Error : Missing floor/ceiling color") : 0;
    (err == -17) ? printf("%s\n", "Error : No starting position") : 0;
    (err == -18) ? printf("%s\n", "Error : Multiple starting positions") : 0;
    (err == -19) ? printf("%s\n", "Error : Map isn't surrounded by walls") : 0;
    return (0);
}
