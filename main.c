/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:24:01 by sel-jett          #+#    #+#             */
/*   Updated: 2023/12/26 23:43:36 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main (int ac, char **av)
{
	t_neox	*neox;
	// int		i;

	neox = NULL;
	ft_check_args(ac, av);
	ft_parser(&neox, av);
	// while (neox)
	// {
	// 	i = -1;
	// 	while(++i < 10)
	// 		printf("%d ", neox->line[i]);
	// 	puts("l6wa");
	// 	neox = neox->next;
	// }
	// my_malloc(0, 2);
}
