#include "../inc/cub3d.h"
void ft_check_oneplayer(t_cub_info *info)
{
    int found;
    int i;
    int j;

    found = 0;
    i = -1;
    while (info->map && info->map[++i])
    {
        j = -1;
        while (info->map[i][++j])
        {
            if (info->map[i][j] == 'N' || info->map[i][j] == 'S' ||\
                info->map[i][j] == 'E' || info->map[i][j] == 'W')
                found++;
        }
    }
    if (found != 1)
      ft_errfreeexit("There must be 1 player", info);
}
