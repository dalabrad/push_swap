/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:22:38 by dalabrad          #+#    #+#             */
/*   Updated: 2024/05/20 17:00:48 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	if (n >= 0)
		nbr = n;
	else
	{
		nbr = -n;
		len += ft_putchar('-');
	}
	if (nbr < 10)
		len += ft_putchar('0' + nbr);
	else
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	return (len);
}
