#include "../inc/cub3d.h"

void    ft_set_player(t_player_info *player, t_cub_info *info);

int	ft_strchr_r(const char *str, char *check)
{
	int	i[2];

	i[0] = -1;
	if (!str)
		return (-1);
	while (str[++i[0]])
	{
		i[1] = -1;
		while (check[++i[1]])
		{
			if (str[i[0]] == check[i[1]])
				return (i[0]);
		}
	}
	return (-1);
}

int	ft_strchr_i(const char *s, int c)
{
	unsigned char	u_char;
	int				i;

	i = 0;
	if (!s)
		return (-1);
	u_char = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == u_char)
			return (i);
		i++;
	}
	if (u_char == '\0')
		return (i);
	return (-1);
}

double  find_player_x(t_player_info *player, t_cub_info *info)
{
    int i;

    i = -1;
    while (info->map[++i])
    {
        if (ft_strchr_r(info->map[i], "NSWE") != -1)
            return (ft_strchr_r(info->map[i], "NSWE") + 0.5f);
    }
    return (-1);
}

double  find_player_y(t_player_info *player, t_cub_info *info)
{
    int i;

    i = -1;
    while (info->map[++i])
    {
        if (ft_strchr_r(info->map[i], "NSWE") != -1)
            return (i + 0.5f);
    }
    return (-1);
}

void    set_player_rot(t_player_info *player, char c)
{
    if (c == 'E')
    {
        player->xdir = 1;
        player->ydir = 0;
    }
    else if (c == 'N')
    {
        player->xdir = 0;
        player->ydir = 1;
    }
    else if (c == 'W')
    {
        player->xdir = -1;
        player->ydir = 0;
    }
    else if (c == 'S')
    {
        player->xdir = 0;
        player->ydir = -1;
    }
}

void  find_player_rot(t_player_info *player, t_cub_info *info)
{
    int i;

    i = -1;
    while (info->map[++i])
    {
        if (ft_strchr_r(info->map[i], "NSWE") != -1)
        {
            if (ft_strchr_i(info->map[i], 'E') != -1)
                set_player_rot(player, 'E');
            else if (ft_strchr_i(info->map[i], 'N') != -1)
                set_player_rot(player, 'N');
            else if (ft_strchr_i(info->map[i], 'W') != -1)
                set_player_rot(player, 'W');
            else if (ft_strchr_i(info->map[i], 'S') != -1)
                set_player_rot(player, 'S');
        }
    }
}

void    ft_set_player(t_player_info *player, t_cub_info *info)
{
    player->xpos = find_player_x(player, info);
    player->ypos = find_player_y(player, info);
    find_player_rot(player, info);
}