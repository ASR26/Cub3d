/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysmeding <ysmeding@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:19:31 by ysmeding          #+#    #+#             */
/*   Updated: 2023/08/15 15:04:37 by ysmeding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H 

# include "../libft/libft.h"
# include "../MLX/include/MLX42/MLX42.h"

/* close read write */
# include <unistd.h>
/* exit malloc free */
# include <stdlib.h>
/* perror printf */
# include <stdio.h>
/* strerror */
# include <string.h>
/* open */
# include <fcntl.h>
/* errno */
# include <errno.h>

typedef struct s_cub_info
{
	char	**scene;
	char	**map;
	char	*n_wall;
	char	*s_wall;
	char	*w_wall;
	char	*e_wall;
	int		floor_col[3];
	int		ceil_col[3];
}			t_cub_info;

/* ------------------------------- arr_utils.c ------------------------------ */

int		ft_arrlen(char **arr);
char	*ft_strtrimnl(char *str);
char	**ft_arrapp(char **arr, char *app);
char	**ft_arrremove(char **arr, int pos);

/* --------------------------------- cub3d.c -------------------------------- */

int		ft_cub3d(char *scenefile);

/* ------------------------------- errorfunc.c ------------------------------ */

void	ft_errexit(char *errormessage);
void	ft_errfreeexit(char *errormessage, t_cub_info *info);

/* ------------------------------ ft_freefunc.c ----------------------------- */

void	ft_freearr(char **arr);
void	ft_freearr2(char **arr, char **newarr);
void	ft_free_info(t_cub_info *info);

/* ------------------------------- ft_getstr.c ------------------------------ */

int		ft_findchar(char *str, char c);
char	*ft_straddfree(char *str, char chr);
int		ft_addwhilenotchar(char *line, char **name, char c);
char	*ft_getstr(char *line, int len, int *total);

/* ---------------------------- ft_parse_scene.c ---------------------------- */

int		ft_parse_scene(char *scenefile, t_cub_info *info);

#endif