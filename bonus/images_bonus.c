/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:18:16 by ylabbe            #+#    #+#             */
/*   Updated: 2022/06/14 19:22:03 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*		Fais apparaître l'image pour le 'P'		*/
void	perso(t_vars vars, int largeur, int hauteur)
{
	vars.sprite = mlx_xpm_file_to_image(vars.mlx,
			"./images/personnage.xpm", &vars.largeur, &vars.hauteur);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.sprite, largeur, hauteur);
}

/*		Fais apparaître l'image pour les '1'	*/
void	mur(t_vars vars, int largeur, int hauteur)
{
	vars.sprite = mlx_xpm_file_to_image(vars.mlx,
			"./images/mur.xpm", &vars.largeur, &vars.hauteur);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.sprite, largeur, hauteur);
}

/*		Fais apparaître l'image pour les 'C'	*/
void	objets(t_vars vars, int largeur, int hauteur)
{
	vars.sprite = mlx_xpm_file_to_image(vars.mlx,
			"./images/objet.xpm", &vars.largeur, &vars.hauteur);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.sprite, largeur, hauteur);
}

/*		Fais apparaître l'image pour les '0'	*/
void	vide(t_vars vars, int largeur, int hauteur)
{
	vars.sprite = mlx_xpm_file_to_image(vars.mlx,
			"./images/vide.xpm", &vars.largeur, &vars.hauteur);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.sprite, largeur, hauteur);
}

void	sortie(t_vars vars, int largeur, int hauteur)
{
	vars.sprite = mlx_xpm_file_to_image(vars.mlx,
			"./images/sortie_ouverte.xpm", &vars.largeur, &vars.hauteur);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.sprite, largeur, hauteur);
}
