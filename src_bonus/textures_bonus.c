/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 08:42:30 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/21 10:52:28 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	ft_setdraw(t_draw *draw, t_cub_info *cub)
{
	int		i;
	char	*name;

	draw->n_wall = mlx_load_png(cub->n_wall);
	draw->s_wall = mlx_load_png(cub->s_wall);
	draw->w_wall = mlx_load_png(cub->w_wall);
	draw->e_wall = mlx_load_png(cub->e_wall);
	if (cub->door[0] != 0)
		draw->door = mlx_load_png(cub->door);
	draw->weapon = mlx_load_png("./textures/swordframes/sword0.png");
	i = 0;
	while (i < 10)
	{
		name = ft_strjoinfree(ft_strjoinfree("./textures/swordframes/sword", \
		ft_itoa(i + 1), 2), ".png", 1);
		draw->weapon_mv[i] = mlx_load_png(name);
		free (name);
		i++;
	}
	draw->treasurec = mlx_load_png("./textures/treasurechestclose.png");
	draw->treasureo = mlx_load_png("./textures/treasurechestopen.png");
	ft_checkdraw(draw, cub);
}

void	ft_checkdraw(t_draw *draw, t_cub_info *cub)
{
	int i;

	if (!draw->n_wall || !draw->s_wall || !draw->e_wall || !draw->w_wall)
		ft_errfreeexit2("One of the wall textures could not be loaded.", cub,
			draw);
	else if (cub->door[0] != 0 && !draw->door)
		ft_errfreeexit2("The door texture could not be loaded.", cub, draw);
	else if (!draw->treasureo || !draw->treasurec)
		ft_errfreeexit2("The treasure chest texture could not be loaded.",
			cub, draw);
	else if (!draw->weapon)
		ft_errfreeexit2("The weapon texture could not be loaded.", cub, draw);
	i = 0;
	while (i < 10)
	{
		if (!draw->weapon_mv[i])
			ft_errfreeexit2("One of the weapon textures could not be loaded.",
				cub, draw);
		i++;
	}
}
