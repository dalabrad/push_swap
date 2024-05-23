/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:25:45 by dalabrad          #+#    #+#             */
/*   Updated: 2024/04/11 11:03:57 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtrn;
	char	*tmp;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	rtrn = (char *)malloc(sizeof(char) * (len + 1));
	if (rtrn == NULL)
		return (NULL);
	rtrn = (char *)ft_memcpy(rtrn, s1, ft_strlen(s1));
	tmp = rtrn + ft_strlen(s1);
	tmp = (char *)ft_memcpy(tmp, s2, ft_strlen(s2));
	rtrn[len] = '\0';
	return (rtrn);
}
