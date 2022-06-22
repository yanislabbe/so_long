/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_du_personnage_suite.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:18:10 by ylabbe            #+#    #+#             */
/*   Updated: 2022/06/14 19:18:11 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	Si pos_x est plus petit que la largeur de la carte,
 *	le tableau de pointeur pos_y pos_x n'égal pas 1 (mur),
 *	le tableau de pointeur pos_y pos_x peut se déplacer sur 0 (vide),
 *	sinon le tableau de pointeur pos_y pos_x peut se déplacer sur C
 *		et il baisse le nombre de collectible total restant,
 *		si il n'y a plus de collectible, la sortie s'ouvre
 *	sinon quand la sortie (E) est ouverte, ça ferme la fenêtre.	*/
void	press_a(t_vars *vars, int *pos_x, int *pos_y, t_carte *carte)
{
	if (*pos_x < vars->carte->largeur)
	{
		if (carte->pos[*pos_y][*pos_x - 1] != '1')
		{
			if (carte->pos[*pos_y][*pos_x - 1] == '0')
				deplacement_du_personnage(vars, 'a');
			else if (carte->pos[*pos_y][*pos_x - 1] == 'C')
			{
				carte->pos[*pos_y][*pos_x - 1] = '0';
				deplacement_du_personnage(vars, 'a');
				vars->carte->collectible--;
				if (vars->carte->collectible == 0)
					ouvert((*vars), carte->quit_x * 32, carte->quit_y * 32);
			}
			else if (carte->pos[*pos_y][*pos_x - 1] == 'E')
				victoire(vars);
		}
	}
}

void	press_s(t_vars *vars, int *pos_x, int *pos_y, t_carte *carte)
{
	if (*pos_x < vars->carte->largeur)
	{
		if (carte->pos[*pos_y + 1][*pos_x] != '1')
		{
			if (carte->pos[*pos_y + 1][*pos_x] == '0')
				deplacement_du_personnage(vars, 's');
			else if (carte->pos[*pos_y + 1][*pos_x] == 'C')
			{
				carte->pos[*pos_y + 1][*pos_x] = '0';
				deplacement_du_personnage(vars, 's');
				vars->carte->collectible--;
				if (vars->carte->collectible == 0)
					ouvert((*vars), carte->quit_x * 32, carte->quit_y * 32);
			}
			else if (carte->pos[*pos_y + 1][*pos_x] == 'E')
				victoire(vars);
		}
	}
}

void	press_d(t_vars *vars, int *pos_x, int *pos_y, t_carte *carte)
{
	if (*pos_x < vars->carte->largeur)
	{
		if (carte->pos[*pos_y][*pos_x + 1] != '1')
		{
			if (carte->pos[*pos_y][*pos_x + 1] == '0')
				deplacement_du_personnage(vars, 'd');
			else if (carte->pos[*pos_y][*pos_x + 1] == 'C')
			{
				carte->pos[*pos_y][*pos_x + 1] = '0';
				deplacement_du_personnage(vars, 'd');
				vars->carte->collectible--;
				if (vars->carte->collectible == 0)
					ouvert((*vars), carte->quit_x * 32, carte->quit_y * 32);
			}
			else if (carte->pos[*pos_y][*pos_x + 1] == 'E')
				victoire(vars);
		}
	}
}

void	press_w(t_vars *vars, int *pos_x, int *pos_y, t_carte *carte)
{
	if (*pos_x < vars->carte->largeur)
	{
		if (carte->pos[*pos_y - 1][*pos_x] != '1')
		{
			if (carte->pos[*pos_y - 1][*pos_x] == '0')
				deplacement_du_personnage(vars, 'w');
			else if (carte->pos[*pos_y - 1][*pos_x] == 'C')
			{
				carte->pos[*pos_y - 1][*pos_x] = '0';
				deplacement_du_personnage(vars, 'w');
				vars->carte->collectible--;
				if (vars->carte->collectible == 0)
					ouvert((*vars), carte->quit_x * 32, carte->quit_y * 32);
			}
			else if (carte->pos[*pos_y - 1][*pos_x] == 'E')
				victoire(vars);
		}
	}
}

void	ouvert(t_vars vars, int largeur, int hauteur)
{
	vars.sprite = mlx_xpm_file_to_image(vars.mlx,
			"./images/sortie_fermer.xpm", &vars.largeur, &vars.hauteur);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.sprite, largeur, hauteur);
}
