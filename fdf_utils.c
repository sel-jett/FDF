/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:45:34 by sel-jett          #+#    #+#             */
/*   Updated: 2023/12/26 00:35:31 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		count++;
		line = my_strtok(NULL, " ");
	}
	return (count);
}

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

int	ft_atoi(const char *str)
{
	int			i;
	long int	num;
	int			signe;

	(1 == 1) && (i = 0, signe = 1, num = 0);
	if (str[i] == '-' || str[i] == '+')
	{
		(str[i] == '-') && (signe = -1);
		i++;
	}
	if (!str[i])
		return (my_malloc(0, 0), 0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * signe);
}

int	ft_parser(t_neox *neox, char **av)
{
	char	*line;
	int		fd;

	(void)neox;
	fd = open(av[1], O_RDONLY);
	(fd < 0) && (write(2, "Invalid Permissions\n", 20), exit(1), 0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), my_malloc(0, 0), 0);
	// while (line)
	// {
	// 	count = ft_strlen_line(line);
	// 	neox->line = my_malloc((count * 4), 1);
	// }
	printf(">>>> %d\n", ft_strlen_line(line));
	return (1);
}

void	ft_check_args(int ac, char **av)
{
	(ac != 2) && (write(2, "Invalid Arguments", 18), exit(1), 0);
	(!ft_search(av[1])) && (write(2, "Invalid file type\n", 18), exit(1), 0);
}
