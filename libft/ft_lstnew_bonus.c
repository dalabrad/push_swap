/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:15:23 by dalabrad          #+#    #+#             */
/*   Updated: 2024/04/15 18:27:38 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_new;

	list_new = (t_list *)malloc(sizeof(t_list));
	if (list_new == NULL)
		return (NULL);
	list_new->content = content;
	list_new->next = NULL;
	return (list_new);
}
