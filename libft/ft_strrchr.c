/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:48:18 by dalabrad          #+#    #+#             */
/*   Updated: 2024/04/16 11:43:00 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*aux;

	aux = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			aux = (char *)str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (aux);
}
