/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:34:28 by sel-jett          #+#    #+#             */
/*   Updated: 2023/12/27 19:45:31 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_pow(int x ,int y)
{
	if (x == 0)
		return (0);
	else if (y == 1)
		return (x);
	else if (y == 0)
		return (1);
	return ((x * x) * ft_pow(x, y - 2));
}

int	ft_convert(char *str)
{
	int	i;
	int	ret;
	int	y;

	ret = 0;
	i = 2;
	y = ft_strlen(str) - 3;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret += ((str[i] - 48) * ft_pow(16, y));
		else if (str[i] >= 'a' && str[i] <= 'f')
			ret += ((str[i] - 'a' + 10) * ft_pow(16, y));
		else if (str[i] >= 'A' && str[i] <= 'F')
			ret += ((str[i] - 'a' + 10) * ft_pow(16, y));
		else
			ft_error();
		i++;
		--y;
	}
	return (ret);
}
