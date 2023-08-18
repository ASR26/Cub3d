/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   andres.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 08:49:26 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/18 08:49:41 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANDRES_H
# define ANDRES_H

typedef struct s_draw
{
	mlx_texture_t   *n_wall;
	mlx_texture_t	*s_wall;
	mlx_texture_t	*w_wall;
	mlx_texture_t	*e_wall;
}			t_draw;

#endif