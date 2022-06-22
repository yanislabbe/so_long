/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examen_de_la_carte_suite.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:32:44 by ylabbe            #+#    #+#             */
/*   Updated: 2022/06/14 19:34:57 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*prochaine_ligne(char *fichier, int fd)
{
	char	*temporaire;

	if (fichier != NULL)
		free(fichier);
	fichier = get_next_line(fd);
	temporaire = ft_strtrim(fichier, "\n");
	free(fichier);
	return (temporaire);
}

int	quit(int fd, char *fichier)
{
	if (fd != 0)
		close(fd);
	if (fichier != NULL)
		free(fichier);
	return (false);
}

int	carte_ber(char *carte)
{
	int	count;

	count = 0;
	while (carte[count])
		count++;
	if (carte[count - 1] == 'r' && carte[count - 2] == 'e'
		&& carte[count - 3] == 'b' && carte[count - 4] == '.')
		return (1);
	return (0);
}
