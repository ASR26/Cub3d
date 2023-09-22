/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:19:42 by ysmeding          #+#    #+#             */
/*   Updated: 2023/09/22 16:14:05 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_setdraw(t_draw *draw, t_cub_info *cub)
{
	draw->n_wall = mlx_load_png(cub->n_wall);
	draw->s_wall = mlx_load_png(cub->s_wall);
	draw->w_wall = mlx_load_png(cub->w_wall);
	draw->e_wall = mlx_load_png(cub->e_wall);
	ft_checkdraw(draw, cub);
}

void	ft_checkdraw(t_draw *draw, t_cub_info *cub)
{
	if (!draw->n_wall || !draw->s_wall || !draw->e_wall || !draw->w_wall)
		ft_errfreeexit2("One of the wall textures could not be loaded.", cub,
			draw);
}
