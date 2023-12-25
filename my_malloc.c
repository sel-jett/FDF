/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:58:00 by sel-jett          #+#    #+#             */
/*   Updated: 2023/12/25 22:06:49 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dataclear(t_data **head)
{
	t_data	*temp;
	t_data	*ptr;

	if (!head || !*head)
		return ;
	temp = *head;
	while (temp)
	{
		ptr = temp->next;
		free(temp->data);
		free(temp);
		temp = ptr;
	}
	*head = NULL;
}

void	*my_malloc(int size, int mode)
{
	static t_data	*head;
	t_data			*node;
	void			*data;

	if (mode == 1)
	{
		data = malloc(size);
		if (!data)
			return (dataclear(&head), exit(1), NULL);
		node = malloc(sizeof(t_data));
		if (!node)
			return (dataclear(&head), exit(1), NULL);
		node->next = NULL;
		(head) && (node->next = head);
		head = node;
		return (data);
	}
	if (!mode)
		return (dataclear(&head), exit(1), NULL);
	return (dataclear(&head), exit(0), NULL);
}
