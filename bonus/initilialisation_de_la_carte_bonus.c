/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carte_initialisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:18:02 by ylabbe            #+#    #+#             */
/*   Updated: 2022/06/15 14:23:23 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*	Permet de lire un fichier	*/
void	carte_initialisation(char *fichier, t_carte *carte)
{
	char	*trim;
	int		fd;

	fd = 0;
	trim = ft_strtrim(fichier, " ");
	fd = open(trim, O_RDONLY);
	if (fd == -1)
	{
		quit(fd, trim);
		return ;
	}
	carte_initialisation_second(fd, carte);
	carte->mouvement = 0;
	quit(fd, trim);
}

/*	Ouvre la fenêtre	*/
void	carte_initialisation_second(int fd, t_carte *carte)
{
	char	*str;
	int		y;

	str = prochaine_ligne(NULL, fd);
	carte->largeur = ft_strlen(str);
	y = 0;
	carte->collectible = 0;
	while (str != NULL)
	{
		carte_initialisation_trois(carte, y, str);
		str = prochaine_ligne(str, fd);
		y++;
		if (y > 100)
			return ;
		if (str == NULL)
			break ;
	}
	carte->hauteur = y;
	if (str != NULL)
		free(str);
	close(fd);
}

/*	Fais apparaitre les éléments au bon endroit	*/
void	carte_initialisation_trois(t_carte *carte, int y, char *str)
{
	int	x;

	x = 0;
	while (x < carte->largeur)
	{
		if (str[x] == 'P')
		{
			carte->pos_x = x;
			carte->pos_y = y;
		}
		if (str[x] == 'E')
		{
			carte->quit_x = x;
			carte->quit_y = y;
		}
		if (str[x] == 'X')
		{
			carte->quit_x = x;
			carte->quit_y = y;
		}
		if (str[x] == 'C')
			carte->collectible++;
		carte->pos[y][x] = str[x];
		x++;
	}
}
