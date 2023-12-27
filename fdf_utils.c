/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:45:34 by sel-jett          #+#    #+#             */
/*   Updated: 2023/12/27 15:36:12 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	ft_search(char *str)
{
	char	ptr[4];
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	ptr[0] = '.';
	ptr[1] = 'f';
	ptr[2] = 'd';
	ptr[3] = 'f';
	while (str[i])
	{
		if (str[i] == '.')
		{
			j = i;
			while (str[j] && str[j] == ptr[k])
				(j++) && (k++);
			if (k == 4 && !str[j])
				return (1);
		}
		i++;
	}
	return (0);
}

int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen_line(char *str)
{
	int		count;
	char	*line;

	line = my_strtok(str, " ");
	count = 0;
	if (!line)
		return (0);
	while (line)
	{
		if (ft_atoi(line) >= 0 || ft_atoi(line) <= 0)
			count++;
		line = my_strtok(NULL, " ");
	}
	return (count);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	num;
	int			signe;
	int			check;

	(1) && (i = 0, signe = 1, num = 0, check = 0);
	if (str[i] == '-' || str[i] == '+')
	{
		(str[i] == '-') && (signe = -1);
		i++;
	}
	if (!str[i])
		return (write(2, "Input Error\n", 12), my_malloc(0, 0), 0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
		check = 1;
	}
	(str[i] || !check) && (ft_error(), 0);
	return (num * signe);
}

t_neox	*ft_lstlast(t_neox *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_neox **lst, t_neox *new)
{
	t_neox	*node;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	node->next = new;
}

void	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

void	ft_parser(t_neox **neox, char **av)
{
	char	*line;
	char	*str;
	int		i;
	int		fd;
	int		count;
	int		nb;
	char	*line2;
	t_neox	*node;

	count = 0;
	node = my_malloc(sizeof(t_neox), 1);
	fd = open(av[1], O_RDONLY);
	(fd < 0) && (write(2, "Invalid Permissions\n", 20), exit(1), 0);
	line = get_next_line(fd);
	(!line) && (close(fd), my_malloc(0, 0), 0);
	*neox = node;
	while (line)
	{
		line2 = malloc(ft_strlen(line) + 1);
		line2 = ft_strcpy(line, line2);
		str = my_strtok(line, " \t");
		while (str)
		{
			nb = ft_atoi(str);
			count++;
			str = my_strtok(NULL, " \t");
		}
		node->line = my_malloc(4 * count, 1);
		i = 0;
		str = my_strtok(line2, " \t");
		while (str)
		{
			nb = ft_atoi(str);
			node->line[i] = nb;
			str = my_strtok(NULL, " \t");
			i++;
		}
		free(line);
		free(line2);
		line = get_next_line(fd);
		if (line)
			node->next = my_malloc(sizeof(t_neox), 1);
		node = node->next;
		if (node)
			node->next = NULL;
	}
}

void	ft_check_args(int ac, char **av)
{
	(ac != 2) && (write(2, "Invalid Arguments", 18), exit(1), 0);
	(!ft_search(av[1])) && (write(2, "Invalid file type\n", 18), exit(1), 0);
}
