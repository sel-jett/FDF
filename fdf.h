/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:29:07 by sel-jett          #+#    #+#             */
/*   Updated: 2023/12/27 15:34:54 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_neox
{
	int				*line;
	struct s_neox	*next;
}	t_neox;

typedef struct s_data
{
	void			*data;
	struct s_data	*next;
}	t_data;

void	ft_error();
void	*my_malloc(size_t size, int mode);
size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);
char	*my_strtok(char *src, char *delim);
void	ft_check_args(int ac, char **av);
void	ft_parser(t_neox **neox, char **av);
char	*my_strcpy(char *s1, char *s2, char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_all(int fd, char *str);
char	*get_next_line(int fd);
int		find_line(char *str);
char	*get_the_line(char *str);
char	*get_the_rest(char *str, size_t size);
int		ft_str_line(char *str);

#endif
