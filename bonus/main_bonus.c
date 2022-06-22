/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:09:14 by ylabbe            #+#    #+#             */
/*   Updated: 2022/06/14 19:32:03 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	data;
	t_carte	carte;

	if (argc != 2 || verification_carte(argv[1]) == false)
	{
		ft_printf("Error: arguments ou carte invalide.\n");
		return (0);
	}
	carte_initialisation(argv[1], &carte);
	vars.carte = &carte;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, carte.largeur * 32,
			carte.hauteur * 32, "so long");
	data.img = mlx_new_image(vars.mlx, 0, 0);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, data.img, 0, 0);
	emplacements_des_objets(vars, carte);
	vars.carte->pos[carte.pos_y][carte.pos_x] = '0';
	mlx_key_hook(vars.win, keyboard, &vars);
	mlx_hook(vars.win, 17, 0, bouton_pour_fermer_la_fenetre, 0);
	mlx_loop(vars.mlx);
}
