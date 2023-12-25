/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 00:25:29 by sel-jett          #+#    #+#             */
/*   Updated: 2023/12/26 00:26:00 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char	*my_strtok(char *src, char *delim)
{
	static char	*backup;
	char		*ret;

	(!src) && (src = backup);
	if (!src)
		return (NULL);
	while (1)
	{
		while (is_delim(*src, delim))
			src++;
		if (*src == '\0')
			return (NULL);
		break ;
	}
	ret = src;
	while (1)
	{
		if (*src == '\0')
			return (backup = src, ret);
		if (is_delim(*src, delim))
			return (*src = '\0', backup = src + 1, ret);
		src++;
	}
}
