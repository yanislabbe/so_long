/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_suite_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:21:27 by ylabbe            #+#    #+#             */
/*   Updated: 2022/06/15 14:52:27 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	perdu(void)
{
	ft_printf("Tu as perdu!\n");
	exit(0);
}

void	ennemie(t_vars vars, int largeur, int hauteur)
{
	vars.sprite = mlx_xpm_file_to_image(vars.mlx,
			"./images/x_bonus.xpm", &vars.largeur, &vars.hauteur);
	mlx_put_image_to_window(vars.mlx, vars.win, vars. sprite, largeur, hauteur);
}
