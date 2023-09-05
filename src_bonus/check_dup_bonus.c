#include "../inc/cub3d_bonus.h"

//void	ft_skipspace(char *line, int *len);

void	ft_check_dup_in_line(char *line, t_cub_info *info, int *ct)
{
	(void)info;//??
	if (ft_strlen(line) >= 2 && line[0] == 'N' && line[1] == 'O')
		*ct += 1;
	else if (ft_strlen(line) >= 2 && line[0] == 'S' && line[1] == 'O')
		*ct += 2;
	else if (ft_strlen(line) >= 2 && line[0] == 'W' && line[1] == 'E')
		*ct += 3;
	else if (ft_strlen(line) >= 2 && line[0] == 'E' && line[1] == 'A')
    	*ct += 4;
	else if (ft_strlen(line) >= 1 && line[0] == 'F')
		*ct += 5;
	else if (ft_strlen(line) >= 1 && line[0] == 'C')
		*ct += 6;
	return ;
}

void    ft_check_dup_param(t_cub_info *info)
{
    int i;
    int j;
    int ct;

    i = 0;
    ct = 0;
    while (info->scene[i])
	{
		j = 0;
		ft_skipspace(info->scene[i], &j);
		if (!info->scene[i][j])
		{
			info->scene = ft_arrremove(info->scene, i);
			i--;
		}
		else
			ft_check_dup_in_line(&(info->scene[i][j]), info, &ct);
		i++;
	}
	if (ct != 21)
		ft_errfreeexit("Duplicated parameter in scene file", info);
}