/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:29:07 by sel-jett          #+#    #+#             */
/*   Updated: 2023/12/25 22:07:05 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	void			*data;
	struct s_data	next;
}	t_data;

void	ft_check_args(int ac, char **av);
void	*my_malloc(int size, int mode);

#endif
