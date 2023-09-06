/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:12:43 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/06 11:15:45 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cub3d_bonus.h"

//double	ft_setang(double ang);

float   ft_dist(t_cub_info *cub, t_player_info *player, int idx)
{
    float dist;
    float diffx;
    float diffy;

    diffx = player->xpos - (cub->doorx[idx] + 0.5f);
    diffy = player->ypos - (cub->doory[idx] + 0.5f);
    dist = sqrt(diffx * diffx + diffy * diffy);
    return (dist);
}

int ft_checkdiagmove(t_cub_info *cub, t_player_info *player, int tmp[2])
{
    if (ft_floor(tmp[0]) == ft_floor(player->xpos) + 1)
    {
        if (ft_floor(tmp[1]) == ft_floor(player->ypos) + 1)
        {
            if (cub->map[ft_floor(player->ypos)][ft_floor(player->xpos) + 1] == '1' && cub->map[ft_floor(player->ypos) + 1][ft_floor(player->xpos)] == '1')
                return (-1);
        }
        else if (ft_floor(tmp[1]) == ft_floor(player->ypos) - 1 )
        {
            if (cub->map[ft_floor(player->ypos) - 1][ft_floor(player->xpos)] == '1' && cub->map[ft_floor(player->ypos)][ft_floor(player->xpos) + 1] == '1')
                return (-1);
        }
    }
    else if (ft_floor(tmp[0]) == ft_floor(player->xpos) - 1)
    {
        if (ft_floor(tmp[1]) == ft_floor(player->ypos) + 1)
        {
            if (cub->map[ft_floor(player->ypos)][ft_floor(player->xpos) - 1] == '1' && cub->map[ft_floor(player->ypos) + 1][ft_floor(player->xpos)] == '1')
                return (-1);
        }
        else if (ft_floor(tmp[1]) == ft_floor(player->ypos) - 1 )
        {
            if (cub->map[ft_floor(player->ypos) - 1][ft_floor(player->xpos)] == '1' && cub->map[ft_floor(player->ypos)][ft_floor(player->xpos) - 1] == '1')
                return (-1);
        }
    }
    return (0);
}

void    move_player_front(t_cub_info *cub, t_player_info *player, int i)
{
    int tmp[2];
    int idx;

    tmp[0] = player->xpos + MOV_SPEED * player->xdir * i;
    tmp[1] = player->ypos + MOV_SPEED * player->ydir * i;
    if (cub->map[tmp[1]][tmp[0]] != '1' && cub->map[tmp[1]][tmp[0]] != 'D')
    {
        if (!ft_checkdiagmove(cub, player, tmp))
        {
            player->xpos += MOV_SPEED * player->xdir * i;
            player->ypos += MOV_SPEED * player->ydir * i;
            idx = 0;
            while (idx < 5)
            {
                if (cub->doordir[idx])
                {
                    if (ft_dist(cub, player, idx) > 1.5)
                    {
                        cub->map[cub->doory[idx]][cub->doorx[idx]] = 'D';
                        cub->doordir[idx] = 0;
                        cub->doorx[idx] = 0;
                        cub->doory[idx] = 0;
                    }
                }
                idx++;
            }
        }
    }
}

void    move_player_lateral(t_cub_info *cub, t_player_info *player, int i)
{
    int tmp[2];
    int idx;

    tmp[0] = player->xpos + MOV_SPEED * player->xcamera * i;
    tmp[1] = player->ypos + MOV_SPEED * player->ycamera * i;
    if (cub->map[tmp[1]][tmp[0]] != '1' && cub->map[tmp[1]][tmp[0]] != 'D')
    {
        if (!ft_checkdiagmove(cub, player, tmp))
        {
            player->xpos += MOV_SPEED * player->xcamera * i;
            player->ypos += MOV_SPEED * player->ycamera * i;
            idx = 0;
            while (idx < 5)
            {
                if (cub->doordir[idx])
                {
                    if (ft_dist(cub, player, idx) > 1.5)
                    {
                        cub->map[cub->doory[idx]][cub->doorx[idx]] = 'D';
                        cub->doordir[idx] = 0;
                        cub->doorx[idx] = 0;
                        cub->doory[idx] = 0;
                    }
                }
                idx++;
            }
        }
    }
}

void    move_player(t_cub_info *cub, t_player_info *player, int i)
{
    if (i == 'W')
        move_player_front(cub, player, -1);
    if (i == 'S')
        move_player_front(cub, player, 1);
    if (i == 'A')
        move_player_lateral(cub, player, -1);
    if (i == 'D')
        move_player_lateral(cub, player, 1);
}

void    rot_player(t_player_info *player, int i)
{
    rotate_z(&player->xdir, &player->ydir, ROT_SPEED * i); //i is the direction to rotate
    rotate_z(&player->xcamera, &player->ycamera, ROT_SPEED * i);
    player->pov += ROT_SPEED * i;
    player->pov = ft_setang(player->pov);
}

void    rot_player_mouse(t_player_info *player, int i, float vel)
{
    rotate_z(&player->xdir, &player->ydir, vel* i); //i is the direction to rotate
    rotate_z(&player->xcamera, &player->ycamera, vel * i);
    player->pov += vel * i;
    player->pov = ft_setang(player->pov);
}