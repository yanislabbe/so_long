/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_du_personnage.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:18:02 by ylabbe            #+#    #+#             */
/*   Updated: 2022/06/14 19:18:03 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	deplacement_du_personnage(t_vars *vars, int keycode)
{
	if (keycode == 'a')
	{
		perso((*vars), (vars->carte->pos_x - 1) * 32, vars->carte->pos_y * 32);
		vide((*vars), (vars->carte->pos_x) * 32, vars->carte->pos_y * 32);
		vars->carte->pos_x--;
	}
	else if (keycode == 's')
	{
		perso((*vars), vars->carte->pos_x * 32, (vars->carte->pos_y + 1) * 32);
		vide((*vars), vars->carte->pos_x * 32, vars->carte->pos_y * 32);
		vars->carte->pos_y++;
	}
	else if (keycode == 'd')
	{
		perso((*vars), (vars->carte->pos_x + 1) * 32, vars->carte->pos_y * 32);
		vide((*vars), vars->carte->pos_x * 32, vars->carte->pos_y * 32);
		vars->carte->pos_x++;
	}
	else if (keycode == 'w')
	{
		perso((*vars), vars->carte->pos_x * 32, (vars->carte->pos_y - 1) * 32);
		vide((*vars), vars->carte->pos_x * 32, vars->carte->pos_y * 32);
		vars->carte->pos_y--;
	}
	ft_printf("Mouvements = %d\n", ++vars->carte->mouvement);
}

void	emplacements_des_objets(t_vars vars, t_carte carte)
{
	carte.pos_y = 0;
	while (carte.pos_y < carte.hauteur)
	{
		carte.pos_x = 0;
		while (carte.pos_x < carte.largeur)
		{
			if (carte.pos[carte.pos_y][carte.pos_x] == '0')
				vide(vars, carte.pos_x * 32, carte.pos_y * 32);
			else if (carte.pos[carte.pos_y][carte.pos_x] == '1')
				mur(vars, carte.pos_x * 32, carte.pos_y * 32);
			else if (carte.pos[carte.pos_y][carte.pos_x] == 'C')
				objets(vars, carte.pos_x * 32, carte.pos_y * 32);
			else if (carte.pos[carte.pos_y][carte.pos_x] == 'P')
				perso(vars, carte.pos_x * 32, carte.pos_y * 32);
			else if (carte.pos[carte.pos_y][carte.pos_x] == 'E')
				sortie(vars, carte.pos_x * 32, carte.pos_y * 32);
			carte.pos_x++;
		}
		carte.pos_y++;
	}
	carte.pos[carte.pos_y][carte.pos_x] = '0';
}

int	keyboard(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		ft_printf("Tu as appuyé sur la touche échap.\n");
		exit(0);
	}
	else if (keycode == 0)
		press_a(vars, &vars->carte->pos_x, &vars->carte->pos_y,
			vars->carte);
	else if (keycode == 2)
		press_d(vars, &vars->carte->pos_x, &vars->carte->pos_y,
			vars->carte);
	else if (keycode == 13)
		press_w(vars, &vars->carte->pos_x, &vars->carte->pos_y,
			vars->carte);
	else if (keycode == 1)
		press_s(vars, &vars->carte->pos_x, &vars->carte->pos_y,
			vars->carte);
	return (0);
}

int	bouton_pour_fermer_la_fenetre(void)
{
	ft_printf("Tu as appuyé sur le bouton x de la fenêtre.\n");
	exit(0);
	return (0);
}

void	victoire(t_vars *vars)
{
	if (vars->carte->collectible <= 0)
	{
		ft_printf("Victoire!\n");
		exit(0);
	}
}
